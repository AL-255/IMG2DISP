/* 
 * This file is part of the IMG2DISP distribution (https://github.com/AL-255/IMG2DISP).
 * Copyright (c) 2024 Anhang Li.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include <imgui.h>
#include <imgui_internal.h>

namespace ImGui
{
    template<int steps>
    void bezier_table(ImVec2 P[4], ImVec2 results[steps + 1]);

    float BezierValue(float dt01, float P[4]);

    int Bezier(const char *label, float P[5]);

    void ShowBezierDemo();
}