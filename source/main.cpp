#include "window.h"

using namespace SoftRaster;

constexpr uint32_t WIDTH = 800;
constexpr uint32_t HEIGHT = 600;

int main(int argc, char **argv)
{
    std::shared_ptr<window> m_window = std::make_shared<window>("SoftRaster", WIDTH, HEIGHT);
    std::shared_ptr<framebuffer> m_framebuffer = std::make_shared<framebuffer>(WIDTH, HEIGHT);

    // 程序循环
    bool is_running = true;
    while (is_running)
    {
        // 事件处理
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                is_running = false;
            }
        }
        // 渲染逻辑
        m_framebuffer->clearColor({50, 50, 50, 255});
        // TODO: 实现渲染逻辑
        m_framebuffer->setColor(100, 100, {255, 255, 255, 255});
        m_framebuffer->setColor(101, 100, {255, 255, 255, 255});
        m_framebuffer->setColor(100, 101, {255, 255, 255, 255});
        m_framebuffer->setColor(101, 101, {255, 255, 255, 255});
        m_window->drawFramebuffer(m_framebuffer);
    };
}
