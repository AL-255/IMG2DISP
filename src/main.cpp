// Dear ImGui: standalone example application for SDL2 + SDL_Renderer
// (SDL is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)

// Learn about Dear ImGui:
// - FAQ                  https://dearimgui.com/faq
// - Getting Started      https://dearimgui.com/getting-started
// - Documentation        https://dearimgui.com/docs (same as your local docs/ folder).
// - Introduction, links and more at the top of imgui.cpp

// Important to understand: SDL_Renderer is an _optional_ component of SDL2.
// For a multi-platform app consider using e.g. SDL+DirectX on Windows and SDL+OpenGL on Linux/OSX.

#include "i2d_config.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"
#include <stdio.h>
#include <SDL.h>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_resize2.h"
#include "ini.h"

#include "image_io.hpp"
#include "bezier.hpp"
#include "ImGuiFileDialog.h"


#if !SDL_VERSION_ATLEAST(2,0,17)
#error This backend requires SDL 2.0.17+ because of SDL_RenderGeometry() function
#endif

// Main code
int main(int argc, char** argv) {

    // Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0) {
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }

        // From 2.0.18: Enable native IME.
    #ifdef SDL_HINT_IME_SHOW_UI
        SDL_SetHint(SDL_HINT_IME_SHOW_UI, "1");
    #endif

    // Create window with SDL_Renderer graphics context
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Window* window = SDL_CreateWindow("IMG2DISP", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, window_flags);
    if (window == nullptr)  {printf("Error: SDL_CreateWindow(): %s\n", SDL_GetError());return -1;}
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr){SDL_Log("Error creating SDL_Renderer!");                  return -1;}

    SDL_RendererInfo info;
    SDL_GetRendererInfo(renderer, &info);
    SDL_Log("Current SDL_Renderer: %s", info.name);

    // Minimum Window size
    SDL_SetWindowMinimumSize(window, 640, 480);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);


    // Constants
    static const char* i2d_output_type_alist[]   = { "C array (*.c)"};
    static const char* i2d_scan_mode_alist[]     = { "Horizontal Scan", "Vertical Scan", "Data Hor, Byte Ver", "Data Ver, Byte Hor"};
    static const char* i2d_bpp_alist[]           = { "Monochrome", "4-Index"};
    static const char* i2d_resize_method_alist[] = { "Fit", "Fit Height", "Fit Width", "Stretch", "Center"};
    static const char* i2d_preview_alist[]       = { "Curve", "Tone Mapped", "Dithered"};
    typedef enum { I2D_STATE_IMPORT = 0 \
                 , I2D_STATE_CURVE \
                 , I2D_STATE_MAPPING \
                 , I2D_STATE_DITHERING \
                 , I2D_STATE_MAX } i2d_pipe_state_t;

    // Temporary States
    SDL_Texture* tex_raw;
    SDL_Texture* tex_out;
    SDL_Texture* tex_fmt_preview;

    SDL_Surface* surf_raw;
    SDL_Surface* surf_raw_preview;
    SDL_Surface* surf_preview_ia;
    SDL_Surface* surf_preview_tm;

    // Fill tex_raw_preview with 0,0,0
    surf_raw  = SDL_CreateRGBSurface(0, 1, 1, 32, 0, 0, 0, 0); // Not useful
    surf_raw_preview = SDL_CreateRGBSurface(0, I2D_PREVIEW_WIDTH, I2D_PREVIEW_HEIGHT, 32, 0, 0, 0, 0);
    surf_preview_ia  = SDL_CreateRGBSurface(0, I2D_PREVIEW_WIDTH, I2D_PREVIEW_HEIGHT, 32, 0, 0, 0, 0);
    surf_preview_tm   = SDL_CreateRGBSurface(0, I2D_PREVIEW_WIDTH, I2D_PREVIEW_HEIGHT, 32, 0, 0, 0, 0);
    SDL_FillRect(surf_raw_preview, NULL, SDL_MapRGB(surf_raw_preview->format, 0, 0, 0));
    SDL_FillRect(surf_preview_ia,  NULL, SDL_MapRGB(surf_preview_ia->format, 0, 0, 0));
    SDL_FillRect(surf_preview_tm,  NULL, SDL_MapRGB(surf_preview_tm->format, 0, 0, 0));
    tex_out  = SDL_CreateTextureFromSurface(renderer, surf_preview_ia);

    int  img_src_width        = -1;
    int  img_src_height       = -1;    
    bool show_demo_window     = false;
    bool show_about           = false;
    bool use_dark_theme       = true;
    bool open_after_saving    = false;
    bool image_loaded         = false;
    bool image_preview_redraw = false;
    float image_src_scale     = 1.0f;
    float image_preview_scale = 1.0f;
    int   image_preview_mode  = 0;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    i2d_pipe_state_t i2d_pipe_state = I2D_STATE_CURVE;
    float histogram[256];

    for (int i = 0; i < 256; i++) histogram[i] = 0.0f;

    // Saved States
    bool  i2d_include_header = true;
    bool  i2d_byte_invert    = false;
    bool  i2d_r2l_scan       = false;
    bool  i2d_b2t_scan       = false;
    bool  i2d_msb_first      = false;
    int   i2d_output_type    = 0;
    int   i2d_scan_mode      = 0;
    int   i2d_bpp_mode       = 0;
    int   i2d_resize_method  = 0;
    int   i2d_target_size[2] = {I2D_PREVIEW_WIDTH,I2D_PREVIEW_HEIGHT};
    int   i2d_threshold[16];
    float i2d_bezier_cp[5]   = { 0.0f, 0.0f, 1.0f, 1.0f };

    for (int i = 0; i < 16; i++) i2d_threshold[i] =0;

    i2d_fmt_il_read(renderer, &tex_fmt_preview, i2d_scan_mode, i2d_bpp_mode, i2d_byte_invert, i2d_msb_first, i2d_r2l_scan, i2d_b2t_scan);

    // Main loop
    bool done = false;
    while (!done) {
        // Poll and handle events (inputs, window resize, etc.)
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
                done = true;
        }
        if (SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED) {
            SDL_Delay(10);
            continue;
        }

        // Start the Dear ImGui frame
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        // Set base window size to the display size
        ImGuiIO& io = ImGui::GetIO();
        ImGui::SetNextWindowSize(io.DisplaySize);
        ImGui::SetNextWindowPos(ImVec2(0, 0));

        // -------------------------------------------------------------------------------------------------------------
        // Main Application Window
        // -------------------------------------------------------------------------------------------------------------
        if(1) {
            ImGui::Begin("##app", (bool*)__null, \
                  ImGuiWindowFlags_NoDecoration 
                | ImGuiWindowFlags_NoBringToFrontOnFocus
                | ImGuiWindowFlags_NoResize
                | ImGuiWindowFlags_MenuBar
            );

            if (ImGui::BeginMenuBar()) { // Menu Bar
                if (ImGui::BeginMenu("File")) {
                    if (ImGui::MenuItem("Open Image",  "Ctrl+O")) {
                        // File Dialog
                        IGFD::FileDialogConfig config;
	                    config.path = ".";
                        ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", "Image files (*.png *.gif *.jpg *.jpeg){.png,.gif,.jpg,.jpeg}", config);
                    }
                    if (ImGui::MenuItem("Export Image","Ctrl+X"))   {
                        // File Dialog
                        IGFD::FileDialogConfig config;
                        config.path = ".";
                        if (i2d_output_type == 0) 
                        ImGuiFileDialog::Instance()->OpenDialog("SaveImageDlgKey", "Save Image", "Image files (*.png *.gif *.jpg *.jpeg){.png,.gif,.jpg,.jpeg}", config);
                    }
                    if (ImGui::MenuItem("Export Data", "Ctrl+S"))   {
                        // File Dialog
                        IGFD::FileDialogConfig config;
                        config.path = ".";
                        char* filter;
                        if (i2d_output_type == 0) {
                            filter = "C array (*.c){.c}";
                        } else {
                            // ...
                        }
                        ImGuiFileDialog::Instance()->OpenDialog("SaveDataDlgKey", "Save Data", filter, config);
                    }
                    ImGui::Separator();
                    // Configurations
                    if (ImGui::MenuItem("Save Config", NULL))   {
                        // Write config.ini
                        mINI::INIFile file("config.ini");
                        mINI::INIStructure ini;
                        ini["Settings"]["IncludeHeader"]   = std::to_string(i2d_include_header);
                        ini["Settings"]["ByteInvert"]      = std::to_string(i2d_byte_invert);
                        ini["Settings"]["RightToLeftScan"] = std::to_string(i2d_r2l_scan);
                        ini["Settings"]["BottomToTopScan"] = std::to_string(i2d_b2t_scan);
                        ini["Settings"]["OutputType"]      = std::to_string(i2d_output_type);
                        ini["Settings"]["ScanMode"]        = std::to_string(i2d_scan_mode);
                        ini["Settings"]["ResizeMethod"]    = std::to_string(i2d_resize_method);
                        ini["Settings"]["TargetWidth"]     = std::to_string(i2d_target_size[0]);
                        ini["Settings"]["TargetHeight"]    = std::to_string(i2d_target_size[1]);
                        file.write(ini);

                     }
                    if (ImGui::MenuItem("Load Config", NULL))   {
                        // Read config.ini
                        mINI::INIFile file("config.ini");
                        mINI::INIStructure ini;
                        file.read(ini);
                        i2d_include_header = std::stoi(ini["Settings"]["IncludeHeader"]);
                        i2d_byte_invert    = std::stoi(ini["Settings"]["ByteInvert"]);
                        i2d_r2l_scan       = std::stoi(ini["Settings"]["RightToLeftScan"]);
                        i2d_b2t_scan       = std::stoi(ini["Settings"]["BottomToTopScan"]);
                        i2d_output_type    = std::stoi(ini["Settings"]["OutputType"]);
                        i2d_scan_mode      = std::stoi(ini["Settings"]["ScanMode"]);
                        i2d_resize_method  = std::stoi(ini["Settings"]["ResizeMethod"]);
                        i2d_target_size[0] = std::stoi(ini["Settings"]["TargetWidth"]);
                        i2d_target_size[1] = std::stoi(ini["Settings"]["TargetHeight"]);
                    }
                    ImGui::Separator();
                    if (ImGui::MenuItem("Exit", "Ctrl+W"))  { done = true; }
                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Config")) {
                    if (ImGui::MenuItem("Dark Theme", NULL, use_dark_theme)) {
                        use_dark_theme = true;
                        if (use_dark_theme) ImGui::StyleColorsDark();
                        else                ImGui::StyleColorsLight();
                    }
                    if (ImGui::MenuItem("Light Theme", NULL, !use_dark_theme)) {
                        use_dark_theme = false;
                        if (use_dark_theme) ImGui::StyleColorsDark();
                        else                ImGui::StyleColorsLight();
                    }
                    // Show Debug Window
                    if (ImGui::MenuItem("Show Debug Window", NULL, show_demo_window)) {
                        show_demo_window = !show_demo_window;
                    }
                    ImGui::Separator();
                    if (ImGui::MenuItem("Open Saved File", NULL, open_after_saving)) { 
                        open_after_saving = !open_after_saving;
                    }

                    ImGui::EndMenu();
                }
                if (ImGui::BeginMenu("Help")) {
                    if (ImGui::MenuItem("About")) { show_about=true; }
                    ImGui::EndMenu();
                }
                ImGui::EndMenuBar();
            }

            ImGui::Columns(2);  // Note: This is legacy, prefer using tables

            { // Left Sidebar
                ImGui::SetColumnWidth(0, 200);
                ImGui::SeparatorText("Pixel Format Control");
                // Draw fmt_il
                ImGui::SetCursorPosX((ImGui::GetColumnWidth() - I2D_FMT_IL_WIDTH) * 0.5f);
                ImGui::Image((ImTextureID)(intptr_t)tex_fmt_preview, ImVec2(I2D_FMT_IL_WIDTH, I2D_FMT_IL_HEIGHT));
                // Draw a frame around the image
                ImVec2 p = ImGui::GetItemRectMin();
                ImVec2 q = ImGui::GetItemRectMax();
                ImGui::GetWindowDrawList()->AddRect(p, q, IM_COL32(255, 255, 255, 255));
                ImGui::Text("Scan Mode");
                bool redraw_fmt_il = false;
                redraw_fmt_il |= ImGui::Combo("##SM", &i2d_scan_mode, i2d_scan_mode_alist, IM_ARRAYSIZE(i2d_scan_mode_alist));
                redraw_fmt_il |= ImGui::Checkbox("Byte Invert",        &i2d_byte_invert);
                redraw_fmt_il |= ImGui::Checkbox("Right to Left Scan", &i2d_r2l_scan);
                redraw_fmt_il |= ImGui::Checkbox("Bottom to Top Scan", &i2d_b2t_scan); 
                
                if (redraw_fmt_il)
                    i2d_fmt_il_read(renderer, &tex_fmt_preview, i2d_scan_mode, i2d_bpp_mode, i2d_byte_invert, i2d_msb_first, i2d_r2l_scan, i2d_b2t_scan);
                // ImGui::Text("Bits Per Pixel");
                // ImGui::Combo("##BPP", &i2d_bpp_mode, i2d_bpp_alist, IM_ARRAYSIZE(i2d_bpp_alist));
                // ImGui::Checkbox("MSB First", &i2d_msb_first);

                ImGui::SeparatorText("Target Size");
                if(ImGui::InputInt2("##TS", i2d_target_size)) {
                    if (i2d_target_size[0] < 1) i2d_target_size[0] = 1;
                    if (i2d_target_size[1] < 1) i2d_target_size[1] = 1;
                    image_preview_redraw = true;
                }
                ImGui::Text("Resize Method");
                image_preview_redraw |= ImGui::Combo("##RM", &i2d_resize_method, i2d_resize_method_alist, IM_ARRAYSIZE(i2d_resize_method_alist));


                ImGui::SeparatorText("Output Format");
                ImGui::Checkbox("Include Header",     &i2d_include_header);
                ImGui::Combo("##OT", &i2d_output_type, i2d_output_type_alist, IM_ARRAYSIZE(i2d_output_type_alist));

            }
            ImGui::NextColumn();

            { // Image Viewer
                ImGui::SeparatorText("Image Preview");
                if (ImGui::BeginTable("ImageTable", 2, 0)) {
                    ImGui::TableNextColumn();
                    // Input Image
                    // ImGui::Image((ImTextureID)(intptr_t)tex_raw_preview, ImVec2(I2D_PREVIEW_WIDTH,I2D_PREVIEW_HEIGHT));

                    ImGui::BeginChild("##ImageSrcContainer", ImVec2(I2D_PREVIEW_WIDTH, I2D_PREVIEW_HEIGHT), true, \
                        ImGuiWindowFlags_AlwaysHorizontalScrollbar \
                    | ImGuiWindowFlags_AlwaysVerticalScrollbar );

                    ImVec2 src_container_size = ImGui::GetContentRegionAvail();
                    ImGui::Image((ImTextureID)(intptr_t)tex_raw, ImVec2(img_src_width * image_src_scale, img_src_height * image_src_scale));
                    ImGui::EndChild();
                    ImVec2 p = ImGui::GetItemRectMin();
                    ImVec2 q = ImGui::GetItemRectMax();
                    ImGui::GetWindowDrawList()->AddRect(p, q, IM_COL32(255, 255, 255, 255));
                    // ImGui::SetNextItemWidth(src_container_size.x);
                    ImGui::SliderFloat("##SrcScale", &image_src_scale, 0.1f, 5.0f, "Scale: %.2f");
                    ImGui::SameLine();
                    if (ImGui::Button("100\%##Src")) image_src_scale = 1.0f;
                    ImGui::SameLine();
                    if (ImGui::Button("Fit##Src")) {
                        float image_src_scale_w = src_container_size.x / img_src_width;
                        float image_src_scale_h = src_container_size.y / img_src_height;
                        image_src_scale = image_src_scale_w < image_src_scale_h ? image_src_scale_w : image_src_scale_h;
                    }

                    if (!image_loaded) ImGui::Text("No Image Loaded");
                    else               ImGui::Text("Image Size: %d x %d", img_src_width, img_src_height);
                    ImGui::TableNextColumn();

                    // Preview Image
                    ImGui::BeginChild("##ImagePreviewContainer", ImVec2(I2D_PREVIEW_WIDTH, I2D_PREVIEW_HEIGHT), true, \
                        ImGuiWindowFlags_AlwaysHorizontalScrollbar \
                    | ImGuiWindowFlags_AlwaysVerticalScrollbar );
                    ImVec2 preview_container_size = ImGui::GetContentRegionAvail();
                    ImGui::Image((ImTextureID)(intptr_t)tex_out, ImVec2(i2d_target_size[0] * image_preview_scale, i2d_target_size[1] * image_preview_scale));
                    ImGui::EndChild();
                    p = ImGui::GetItemRectMin();
                    q = ImGui::GetItemRectMax();
                    ImGui::GetWindowDrawList()->AddRect(p, q, IM_COL32(255, 255, 255, 255));
                    // ImGui::SetNextItemWidth(preview_container_size.x);
                    ImGui::SliderFloat("##PreviewScale", &image_preview_scale, 0.1f, 5.0f, "Scale: %.2f");
                    ImGui::SameLine();
                    if (ImGui::Button("100\%##Preview")) image_preview_scale = 1.0f;
                    ImGui::SameLine();
                    if (ImGui::Button("Fit##Preview")) {
                        float image_preview_scale_w = preview_container_size.x / i2d_target_size[0];
                        float image_preview_scale_h = preview_container_size.y / i2d_target_size[1];
                        image_preview_scale = image_preview_scale_w < image_preview_scale_h ? image_preview_scale_w : image_preview_scale_h;
                    } 
                    if (ImGui::BeginTabBar("##PreviewTabBar")) {
                        if (ImGui::BeginTabItem("Curve")) {
                            if (image_preview_mode != 0){
                                image_preview_redraw = true;
                            }
                            image_preview_mode = 0;
                            ImGui::EndTabItem();
                        }
                        if (ImGui::BeginTabItem("Tone Mapped")) {
                            if (image_preview_mode != 1){
                                image_preview_redraw = true;
                            }
                            image_preview_mode = 1;
                            ImGui::EndTabItem();
                        }
                        // if (ImGui::BeginTabItem("Dithered")) {
                        // Not yet implemented
                        ImGui::EndTabBar();
                    }
                    ImGui::EndTable();
                }
            }
            // ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);

            { // Image Adjustment
                if (ImGui::BeginTabBar("##TabBar")) {
                    if (ImGui::BeginTabItem("Image Adj.")) {
                        if (i2d_pipe_state != I2D_STATE_CURVE){
                            i2d_pipe_state = I2D_STATE_CURVE;
                            image_preview_redraw = true;
                        }
                        ImGui::BeginTable("##IA_Table", 2, 0);
                        ImGui::TableNextColumn();
                        ImGui::SeparatorText("Curve Adjustment");
                        // Float Sliders
                        image_preview_redraw |= ImGui::SliderFloat2("##IA_P0", i2d_bezier_cp, 0.0f, 1.0f, "%.2f");
                        image_preview_redraw |= ImGui::SliderFloat2("##IA_P1", i2d_bezier_cp + 2, 0.0f, 1.0f, "%.2f");

                        ImGui::TableNextColumn();
                        image_preview_redraw |= ImGui::Bezier( "Linear", i2d_bezier_cp);
                        ImVec2 hist_area = ImGui::GetContentRegionAvail();
                        ImGui::PlotHistogram("##IA_Histogram", histogram, sizeof(histogram)/sizeof(float), 0, NULL, 0, 1.0f, ImVec2(hist_area.x, hist_area.y));

                        ImGui::EndTable();
                        ImGui::EndTabItem();
                    }
                    if (ImGui::BeginTabItem("Tone Mapping")) {
                        if (i2d_pipe_state != I2D_STATE_MAPPING){
                            i2d_pipe_state = I2D_STATE_MAPPING;
                            image_preview_redraw = true;
                        }
                        ImGui::PlotHistogram("##TM_Histogram", histogram, sizeof(histogram)/sizeof(float), 0, NULL, 0, 1.0f, ImVec2(400, 100));
                        ImGui::SetNextItemWidth(400);
                        image_preview_redraw |= ImGui::SliderInt("##SI_Threshold", &i2d_threshold[0], 0, 255, "Threshold: %d");
                        ImGui::EndTabItem();
                    }

                    if(ImGui::BeginTabItem("Dithering")){
                        if (i2d_pipe_state != I2D_STATE_DITHERING){
                            i2d_pipe_state = I2D_STATE_DITHERING;
                            image_preview_redraw = true;
                        }
                        ImGui::Text("Not yet implemented");
                        ImGui::EndTabItem();
                    }

                    ImGui::EndTabBar();
                }
            }
            
            if (image_preview_redraw && image_loaded){ // Handle Image Preview Redraw
                // Update preview image from raw
                // i2d_target_size

                // Free old surfaces
                SDL_FreeSurface(surf_raw_preview);
                SDL_FreeSurface(surf_preview_ia);
                SDL_FreeSurface(surf_preview_tm);
                
                surf_raw_preview = SDL_CreateRGBSurface(0, i2d_target_size[0], i2d_target_size[1], 32, 0, 0, 0, 0); // Scaled raw image
                surf_preview_ia  = SDL_CreateRGBSurface(0, i2d_target_size[0], i2d_target_size[1], 32, 0, 0, 0, 0); // Post Image Adjustment
                surf_preview_tm  = SDL_CreateRGBSurface(0, i2d_target_size[0], i2d_target_size[1], 32, 0, 0, 0, 0); // Post Tone Mapping

                SDL_FillRect(surf_raw_preview, NULL, SDL_MapRGB(surf_raw_preview->format, 0, 0, 0));

                /*
                float aspectRatio = (float)img_src_width / (float)img_src_height;
                int newWidth, newHeight;
                if (aspectRatio > 1.0f) {
                    newWidth = i2d_target_size[1];
                    newHeight = (int)(i2d_target_size[1] / aspectRatio);
                } else {
                    newWidth = (int)(i2d_target_size[0] * aspectRatio);
                    newHeight = i2d_target_size[0];
                }
                SDL_Rect destRect = { (i2d_target_size[0] - newWidth) / 2, (i2d_target_size[1] - newHeight) / 2, newWidth, newHeight };
                */

                // Calculate desireable bonding box based on the i2d_resize_method
                SDL_Rect destRect;
                float srcAspectRatio = (float)img_src_width / (float)img_src_height;
                float dstAspectRatio = (float)i2d_target_size[0] / (float)i2d_target_size[1];

                if (i2d_resize_method==0) {
                    // Zoom to fit, keep aspect ratio
                    if (srcAspectRatio > dstAspectRatio) goto I2D_RESIZE_FIT_HEIGHT;
                    else                                 goto I2D_RESIZE_FIT_WIDTH;
                } else if (i2d_resize_method==1) {
                    I2D_RESIZE_FIT_HEIGHT:
                    // Fit Height
                    int newWidth = (int)(img_src_width * i2d_target_size[1] / img_src_height);
                    int newHeight = i2d_target_size[1];
                    destRect = { (i2d_target_size[0] - newWidth) / 2, 0, newWidth, newHeight };
                } else if (i2d_resize_method==2) {
                    I2D_RESIZE_FIT_WIDTH:
                    // Fit Width
                    int newWidth = i2d_target_size[0];
                    int newHeight = (int)(img_src_height * i2d_target_size[0] / img_src_width);
                    destRect = { 0, (i2d_target_size[1] - newHeight) / 2, newWidth, newHeight };
                } else if (i2d_resize_method==3) {
                    // Stretch to fit
                    destRect = { 0, 0, i2d_target_size[0], i2d_target_size[1] };
                } else if (i2d_resize_method==4) {
                    // Center
                    destRect = { (i2d_target_size[0] - img_src_width) / 2, (i2d_target_size[1] - img_src_height) / 2, img_src_width, img_src_height };
                } else if (i2d_resize_method==5) {
                    // Tile
                    // ...
                }
               
                SDL_BlitScaled(surf_raw, NULL, surf_raw_preview, &destRect);

                Uint8 map[256];
                for (int i = 0; i < 256; i++) map[i] = (Uint8)(255.0f * ImGui::BezierValue(i / 255.0f, i2d_bezier_cp));

                // Update ia
                for (int y = 0; y < i2d_target_size[1]; y++){
                    for (int x = 0; x < i2d_target_size[0]; x++){
                        Uint8 r, g, b, a;
                        Uint32 pixel = *(Uint32*)((Uint8*)surf_raw_preview->pixels + y * surf_raw_preview->pitch + x * surf_raw_preview->format->BytesPerPixel);
                        SDL_GetRGBA(pixel, surf_raw_preview->format, &r, &g, &b, &a);
                        Uint8 gray = (Uint8)(0.299 * r + 0.587 * g + 0.114 * b);
                        // Use Bezier tone mapping
                        Uint8 val = map[gray];
                        *(Uint32*)((Uint8*)surf_preview_ia->pixels + y * surf_preview_ia->pitch + x * 4) = SDL_MapRGB(surf_preview_ia->format, val, val, val);
                    }
                }

                // Update tm
                for (int y = 0; y < i2d_target_size[1]; y++){
                    for (int x = 0; x < i2d_target_size[0]; x++){
                        Uint8 r, g, b, a;
                        Uint32 pixel = *(Uint32*)((Uint8*)surf_preview_ia->pixels + y * surf_preview_ia->pitch + x * surf_preview_ia->format->BytesPerPixel);
                        SDL_GetRGBA(pixel, surf_preview_ia->format, &r, &g, &b, &a);
                        Uint8 val = (Uint8)(0.299 * r + 0.587 * g + 0.114 * b);
                        if (val > i2d_threshold[0]) val = 255;
                        else                        val = 0;
                        *(Uint32*)((Uint8*)surf_preview_tm->pixels + y * surf_preview_tm->pitch + x * 4) = SDL_MapRGB(surf_preview_tm->format, val, val, val);
                    }
                }
            
                switch (image_preview_mode){
                    case 0: tex_out = SDL_CreateTextureFromSurface(renderer, surf_preview_ia); break;
                    case 1: tex_out = SDL_CreateTextureFromSurface(renderer, surf_preview_tm); break;
                    case 2: break;
                }
                
                // Calculate histogram from surf_preview_ia
                for (int i = 0; i < 256; i++) histogram[i] = 0.0f;
                for (int y = 0; y < I2D_PREVIEW_HEIGHT; y++){
                    for (int x = 0; x < I2D_PREVIEW_WIDTH; x++){
                        Uint8 r, g, b, a;
                        Uint32 pixel = *(Uint32*)((Uint8*)surf_preview_ia->pixels + y * surf_preview_ia->pitch + x * surf_preview_ia->format->BytesPerPixel);
                        SDL_GetRGBA(pixel, surf_preview_ia->format, &r, &g, &b, &a);
                        float gray = 0.299 * r + 0.587 * g + 0.114 * b;
                        histogram[(int)gray]++;
                    }
                }
                // Normalize histogram
                float max = 0;
                for (int i = 0; i < 256; i++) max = histogram[i] > max ? histogram[i] : max;
                for (int i = 0; i < 256; i++) histogram[i] = histogram[i]/max;

                image_preview_redraw = false;
            }   

            ImGui::End();
        }

        // -------------------------------------------------------------------------------------------------------------
        // About Window
        // -------------------------------------------------------------------------------------------------------------
        if (show_about)
        {
            ImGui::Begin("About", &show_about);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("ImGui + SDL2 + SDL_Renderer");
            ImGui::Text("Anhang Li (thelithcore@gmail.com)");

            if (ImGui::Button("Close"))
                show_about = false;
            ImGui::End();
        }

        // -------------------------------------------------------------------------------------------------------------
        // File Selector - Load Image
        // -------------------------------------------------------------------------------------------------------------
        ImVec2 maxSize = io.DisplaySize;
        ImVec2 minSize = ImVec2(maxSize.x/2, maxSize.y/2);
        if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey", ImGuiWindowFlags_NoCollapse, minSize, maxSize)) {
            if (ImGuiFileDialog::Instance()->IsOk()) {
                std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
                std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();
                // Load image from file
                FILE* f = fopen(filePathName.c_str(), "rb");
                if (f == NULL) {
                    fprintf(stderr, "Failed to open file: %s\n", filePathName.c_str());
                    return false;
                }
                fseek(f, 0, SEEK_END);
                size_t file_size = (size_t)ftell(f);
                fseek(f, 0, SEEK_SET);
                void* file_data = IM_ALLOC(file_size);
                fread(file_data, 1, file_size, f);

                int channels = 4;
                unsigned char* image_data = stbi_load_from_memory((const unsigned char*)file_data, file_size, &img_src_width, &img_src_height, NULL, channels);
                if (image_data == nullptr){
                    fprintf(stderr, "Failed to load image: %s\n", stbi_failure_reason());
                    return false;
                }
                IM_FREE(file_data);

                surf_raw = SDL_CreateRGBSurfaceFrom((void*)image_data, img_src_width, img_src_height, channels * 8, channels * img_src_width, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
                if (surf_raw == nullptr){
                    fprintf(stderr, "Failed to create SDL surface: %s\n", SDL_GetError());
                    return false;
                }


                tex_raw = SDL_CreateTextureFromSurface(renderer, surf_raw);
                
                image_preview_redraw = true;
                image_loaded = true;
            }
            
            ImGuiFileDialog::Instance()->Close();
        }


        // -------------------------------------------------------------------------------------------------------------
        // File Selector - Save Data
        // -------------------------------------------------------------------------------------------------------------
        if (ImGuiFileDialog::Instance()->Display("SaveDataDlgKey", ImGuiWindowFlags_NoCollapse, minSize, maxSize)) {
            if (ImGuiFileDialog::Instance()->IsOk()) {
                std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
                std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();
                // Save data to file
                FILE* f = fopen(filePathName.c_str(), "wb");
                if (f == NULL) {
                    fprintf(stderr, "Failed to open file: %s\n", filePathName.c_str());
                    return false;
                }
                // Write data to file
                fclose(f);
            }
            ImGuiFileDialog::Instance()->Close();
        }


        // -------------------------------------------------------------------------------------------------------------
        // File Selector - Save Image
        // -------------------------------------------------------------------------------------------------------------
        if (ImGuiFileDialog::Instance()->Display("SaveImageDlgKey", ImGuiWindowFlags_NoCollapse, minSize, maxSize)) {
            if (ImGuiFileDialog::Instance()->IsOk()) {
                std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
                std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();
                // Save image to file
                // ...
            }
            ImGuiFileDialog::Instance()->Close();
        }

        // -------------------------------------------------------------------------------------------------------------
        // Demo Window
        // -------------------------------------------------------------------------------------------------------------
        if (show_demo_window) ImGui::ShowDemoWindow(&show_demo_window);

        // Rendering
        ImGui::Render();
        SDL_RenderSetScale(renderer, io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
        SDL_SetRenderDrawColor(renderer, (Uint8)(clear_color.x * 255), (Uint8)(clear_color.y * 255), (Uint8)(clear_color.z * 255), (Uint8)(clear_color.w * 255));
        SDL_RenderClear(renderer);
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);
        SDL_RenderPresent(renderer);
    }

    // Cleanup...
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_FreeSurface(surf_raw);
    SDL_FreeSurface(surf_raw_preview);
    SDL_FreeSurface(surf_preview_ia);
    SDL_FreeSurface(surf_preview_tm);

    SDL_Quit();

    return 0;
}
