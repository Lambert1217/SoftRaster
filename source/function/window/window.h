/**
 * @file window.h
 * @author 刘亚奇 (1904310303@qq.com)
 * @brief 窗口，使用SDL3s
 * @date 2025-04-19
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include "SDL3/SDL.h"
#include "function/graphics/framebuffer.h"

namespace SoftRaster
{
    class Window
    {
    public:
        Window(const std::string &title, uint32_t width, uint32_t height);
        ~Window();

        void drawFramebuffer(const std::shared_ptr<Framebuffer> &framebuffer);

    private:
        std::string title_;
        uint32_t width_, height_;

        SDL_Window *window_;
        SDL_Surface *window_surface_;
    };
} // namespace SoftRaster
