// Dear ImGui: standalone example application for SDL2 + SDL_Renderer
// (SDL is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)

// Learn about Dear ImGui:
// - FAQ                  https://dearimgui.com/faq
// - Getting Started      https://dearimgui.com/getting-started
// - Documentation        https://dearimgui.com/docs (same as your local docs/ folder).
// - Introduction, links and more at the top of imgui.cpp

// Important to understand: SDL_Renderer is an _optional_ component of SDL2.
// For a multi-platform app consider using e.g. SDL+DirectX on Windows and SDL+OpenGL on Linux/OSX.

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"
#include <stdio.h>
#include <SDL.h>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_resize2.h"

// #include "image_io.hpp"
#include "bezier.hpp"
#include "ImGuiFileDialog.h"


#if !SDL_VERSION_ATLEAST(2,0,17)
#error This backend requires SDL 2.0.17+ because of SDL_RenderGeometry() function
#endif

void ProcessImagePreview(SDL_Surface* src, SDL_Surface* dst, float P[4]){
    // Convert src to grayscale, and then write to dst, assume src and dst have the same size 200x200
    // Make Bezier table
    Uint8 map[256];
    for (int i = 0; i < 256; i++){
        map[i] = (Uint8)(255.0f * ImGui::BezierValue(i / 255.0f, P));
    }
    for (int y = 0; y < 200; y++){
        for (int x = 0; x < 200; x++){
            Uint8 r, g, b, a;
            Uint32 pixel = *(Uint32*)((Uint8*)src->pixels + y * src->pitch + x * src->format->BytesPerPixel);
            SDL_GetRGBA(pixel, src->format, &r, &g, &b, &a);
            Uint8 gray = (Uint8)(0.299 * r + 0.587 * g + 0.114 * b);
            // Use Bezier tone mapping
            Uint8 val = map[gray];
            *(Uint32*)((Uint8*)dst->pixels + y * dst->pitch + x * 4) = SDL_MapRGB(dst->format, val, val, val);
        }
    }
}

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
    SDL_Window* window = SDL_CreateWindow("Dear ImGui SDL2+SDL_Renderer example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, window_flags);
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
    static const char* i2d_output_type_alist[] = { "Binary (*.bin)", "C array (*.c)"};
    static const char* i2d_scan_mode_alist[]   = { "Horizontal Scan", "Vertical Scan", "Data Hor, Byte Ver", "Data Ver, Byte Hor"};
    static const char* i2d_bpp_alist[]         = { "Monochrome", "4-Color", "16-Color"};

    // Temporary States
    SDL_Texture* tex_raw;
    SDL_Texture* tex_proc;
    SDL_Texture* tex_out;
    SDL_Surface* surf_raw;
    SDL_Surface* surf_proc;
    SDL_Surface* surf_out;
    // Fill tex_proc with 0,0,0
    {   
        surf_raw  = SDL_CreateRGBSurface(0, 200, 200, 32, 0, 0, 0, 0); // Not useful
        surf_proc = SDL_CreateRGBSurface(0, 200, 200, 32, 0, 0, 0, 0);
        surf_out  = SDL_CreateRGBSurface(0, 200, 200, 32, 0, 0, 0, 0);
        SDL_FillRect(surf_proc, NULL, SDL_MapRGB(surf_proc->format, 0, 0, 0));
        SDL_FillRect(surf_out,  NULL, SDL_MapRGB(surf_out->format, 0, 0, 0));
        tex_proc = SDL_CreateTextureFromSurface(renderer, surf_proc);
        tex_out  = SDL_CreateTextureFromSurface(renderer, surf_out);
    }
    int my_image_width  = -1;
    int my_image_height = -1;    
    bool show_demo_window    = false;
    bool show_about          = false;
    bool use_dark_theme      = true;
    bool open_after_saving   = false;
    bool image_loaded        = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    float v[5] = { 0.0f, 0.0f, 1.0f, 1.0f };

    // Saved States
    bool i2d_include_header = true;
    bool i2d_antitone_byte  = false;
    bool i2d_r2l_scan       = false;
    bool i2d_b2t_scan       = false;
    bool i2d_msb_first      = false;
    int  i2d_output_type = 0;
    int  i2d_scan_mode   = 0;
    int  i2d_bpp_mode    = 0;


    // Main loop
    bool done = false;
    while (!done) {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
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

            // Add a menu bar
            if (ImGui::BeginMenuBar()) {
                if (ImGui::BeginMenu("File")) {
                    if (ImGui::MenuItem("Open Image",  "Ctrl+O")) {
                        // File Dialog
                        IGFD::FileDialogConfig config;
	                    config.path = ".";
                        ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", "Image files (*.png *.gif *.jpg *.jpeg){.png,.gif,.jpg,.jpeg}", config);
                    }
                    if (ImGui::MenuItem("Export Image","Ctrl+X"))   { /* Do stuff */ }
                    if (ImGui::MenuItem("Export Data", "Ctrl+S"))   { /* Do stuff */ }
                    ImGui::Separator();
                    // Configurations
                    if (ImGui::MenuItem("Save Config", NULL))   { /* Do stuff */ }
                    if (ImGui::MenuItem("Load Config", NULL))   { /* Do stuff */ }
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

            ImGui::Columns(2);
            ImGui::SetColumnWidth(0, 200);
                                    
            ImGui::SeparatorText("Pixel Format Control");
            ImGui::Text("Output Type");
            ImGui::Combo("##OT", &i2d_output_type, i2d_output_type_alist, IM_ARRAYSIZE(i2d_output_type_alist));
            ImGui::Text("Scan Mode");
            ImGui::Combo("##SM", &i2d_scan_mode, i2d_scan_mode_alist, IM_ARRAYSIZE(i2d_scan_mode_alist));
            ImGui::Text("Bits Per Pixel");
            ImGui::Combo("##BPP", &i2d_bpp_mode, i2d_bpp_alist, IM_ARRAYSIZE(i2d_bpp_alist));

            ImGui::Checkbox("Include Header", &i2d_include_header);
            ImGui::Checkbox("Antitone Byte", &i2d_antitone_byte);
            ImGui::Checkbox("Right to Left Scan", &i2d_r2l_scan);
            ImGui::Checkbox("Bottom to Top Scan", &i2d_b2t_scan);
            ImGui::Checkbox("MSB First", &i2d_msb_first);

            // Button, gray out if no image is loaded
            if (image_loaded) {
                if (ImGui::Button("Process Image")) {
                    ProcessImagePreview(surf_proc, surf_out, v);
                    tex_out = SDL_CreateTextureFromSurface(renderer, surf_out);
                }
            } else {
                ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.5f, 0.5f, 0.5f, 1.0f));
                ImGui::Button("Process Image");
                ImGui::PopStyleColor();
            }

            ImGui::NextColumn();


            // Create container
            
            ImGui::SeparatorText("Image Preview");

            if (ImGui::BeginTable("ImageTable", 2, 0)) {
                ImGui::TableNextColumn();
                if (!image_loaded) {
                    ImGui::Text("No Image Loaded");
                } else {
                    ImGui::Text("Image Size: %d x %d", my_image_width, my_image_height);
                }
                // Draw the image, retain aspect ratio
                ImGui::Image((ImTextureID)(intptr_t)tex_proc, ImVec2(200,200));
                // Draw a frame around the image
                ImVec2 p = ImGui::GetItemRectMin();
                ImVec2 q = ImGui::GetItemRectMax();
                ImGui::GetWindowDrawList()->AddRect(p, q, IM_COL32(255, 255, 255, 255));

                ImGui::TableNextColumn();

                if (!image_loaded) {
                    ImGui::Text("No Image Loaded");
                } else {
                    ImGui::Text("Image Size: %d x %d", my_image_width, my_image_height);
                }
                // Draw the image, retain aspect ratio
                ImGui::Image((ImTextureID)(intptr_t)tex_out, ImVec2(200,200));
                // Draw a frame around the image
                p = ImGui::GetItemRectMin();
                q = ImGui::GetItemRectMax();
                ImGui::GetWindowDrawList()->AddRect(p, q, IM_COL32(255, 255, 255, 255));

                ImGui::EndTable();
            }

            // Tabs 
            if (ImGui::BeginTabBar("##TabBar")) {
                if (ImGui::BeginTabItem("Image Adj.")) {            
                    if(ImGui::Bezier( "Linear", v)){
                    // Redraw
                    ProcessImagePreview(surf_proc, surf_out, v);
                    tex_out = SDL_CreateTextureFromSurface(renderer, surf_out);
            }
                    ImGui::EndTabItem();
                }
                if (ImGui::BeginTabItem("Tone Mapping")) {
                    ImGui::Text("This is tab 2");
                    ImGui::EndTabItem();
                }
                ImGui::EndTabBar();
            }


            // float y = ImGui::BezierValue( 0.5f, v ); // x delta in [0..1] range
            // ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            ImGui::End();
        }

        // -------------------------------------------------------------------------------------------------------------
        // About Window
        // -------------------------------------------------------------------------------------------------------------
        if (show_about)
        {
            ImGui::Begin("About", &show_about);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("ImGui + SDL2 + SDL_Renderer");
            ImGui::Text("Anhang Li");

            if (ImGui::Button("Close"))
                show_about = false;
            ImGui::End();
        }

        // -------------------------------------------------------------------------------------------------------------
        // File Selector
        // -------------------------------------------------------------------------------------------------------------
        ImVec2 maxSize = io.DisplaySize;
        ImVec2 minSize = ImVec2(maxSize.x/2, maxSize.y/2);
        if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey", ImGuiWindowFlags_NoCollapse, minSize, maxSize)) {
            if (ImGuiFileDialog::Instance()->IsOk()) {
                std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
                std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();
                // LoadTextureFromFile(filePathName.c_str(), renderer, &tex1, &my_image_width, &my_image_height);

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
                unsigned char* image_data = stbi_load_from_memory((const unsigned char*)file_data, file_size, &my_image_width, &my_image_height, NULL, channels);
                if (image_data == nullptr){
                    fprintf(stderr, "Failed to load image: %s\n", stbi_failure_reason());
                    return false;
                }
                IM_FREE(file_data);

                surf_raw = SDL_CreateRGBSurfaceFrom((void*)image_data, my_image_width, my_image_height, channels * 8, channels * my_image_width, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
                if (surf_raw == nullptr){
                    fprintf(stderr, "Failed to create SDL surface: %s\n", SDL_GetError());
                    return false;
                }

                // Resize the image for the 200x200 preview
                surf_proc = SDL_CreateRGBSurface(0, 200, 200, 32, 0, 0, 0, 0);
                SDL_FillRect(surf_proc, NULL, SDL_MapRGB(surf_proc->format, 0, 0, 0));

                float aspectRatio = (float)my_image_width / (float)my_image_height;
                int newWidth, newHeight;
                if (aspectRatio > 1.0f) {
                    newWidth = 200;
                    newHeight = (int)(200 / aspectRatio);
                } else {
                    newWidth = (int)(200 * aspectRatio);
                    newHeight = 200;
                }

                SDL_Rect destRect = { (200 - newWidth) / 2, (200 - newHeight) / 2, newWidth, newHeight };
                SDL_BlitScaled(surf_raw, NULL, surf_proc, &destRect);

                tex_raw  = SDL_CreateTextureFromSurface(renderer, surf_raw);
                tex_proc = SDL_CreateTextureFromSurface(renderer, surf_proc);
                
                ProcessImagePreview(surf_proc, surf_out, v);
                tex_out = SDL_CreateTextureFromSurface(renderer, surf_out);

                image_loaded = true;
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
    SDL_FreeSurface(surf_proc);
    SDL_FreeSurface(surf_out);

    SDL_Quit();

    return 0;
}
