#include "application.h"
#include "config.h"
#include "timer.h"

namespace SoftRaster
{
    Application::Application(const std::string &title, uint32_t width, uint32_t height)
        : title_(title), width_(width), height_(height)
    {
        init();
    }

    Application::~Application()
    {
        terminate();
    }

    void Application::run()
    {
        while (is_running_)
        {
            // 计算delta_time
            auto current_frame_time = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(current_frame_time - last_frame_time_);
            float delta_time = duration.count() * 0.001f; // 单位毫秒
            last_frame_time_ = current_frame_time;
            // 更新一帧
            tick(delta_time);
        }
    }

    void Application::init()
    {
        is_running_ = true;
        last_frame_time_ = std::chrono::high_resolution_clock::now();

        window_ = std::make_shared<Window>(title_, width_, height_);
        framebuffer_ = std::make_shared<Framebuffer>(width_, height_);
    }

    void Application::terminate()
    {
    }

    void Application::tick(float timestep)
    {
        tickEvent(timestep);
        tickRender(timestep);
    }

    void Application::tickEvent(float timestep)
    {
        // 事件处理
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                is_running_ = false;
            }
        }
    }

    void Application::tickRender(float timestep)
    {
        PROFILE_SCOPE("render");
        // 渲染逻辑
        framebuffer_->clearColor(COLOR_GRAY);
        // TODO: 实现渲染逻辑
        framebuffer_->setColor(100, 100, COLOR_WHITE);
        framebuffer_->setColor(101, 100, COLOR_WHITE);
        framebuffer_->setColor(100, 101, COLOR_WHITE);
        framebuffer_->setColor(101, 101, COLOR_WHITE);
        window_->drawFramebuffer(framebuffer_);
    }
} // namespace SoftRaster
