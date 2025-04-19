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
#include "framebuffer.h"

namespace SoftRaster
{
    class window
    {
    public:
        window(const std::string &title, uint32_t width, uint32_t height);
        ~window();

        void drawFramebuffer(const std::shared_ptr<framebuffer> &fb);

    private:
        std::string m_title;
        uint32_t m_width, m_height;

        SDL_Window *m_window;
        SDL_Surface *m_surface;
    };
} // namespace SoftRaster
