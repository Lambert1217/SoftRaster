/**
 * @file application.h
 * @author 刘亚奇 (1904310303@qq.com)
 * @brief 封装程序循环
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include "window.h"
#include "framebuffer.h"

namespace SoftRaster
{
    class Application
    {
    public:
        Application(const std::string &title, uint32_t width, uint32_t height);
        ~Application();

        void run();

    private:
        void init();

        void terminate();

        void tick(float timestep);

        void tickEvent(float timestep);

        void tickRender(float timestep);

    private:
        std::string title_;
        uint32_t width_, height_;

        bool is_running_;
        std::chrono::steady_clock::time_point last_frame_time_;

        std::shared_ptr<Window> window_;
        std::shared_ptr<Framebuffer> framebuffer_;
    };
} // namespace SoftRaster
