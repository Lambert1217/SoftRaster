#include "window.h"
#include "config.h"

using namespace SoftRaster;

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
        m_framebuffer->clearColor(GRAY);
        // TODO: 实现渲染逻辑
        m_framebuffer->setColor(100, 100, WHITE);
        m_framebuffer->setColor(101, 100, WHITE);
        m_framebuffer->setColor(100, 101, WHITE);
        m_framebuffer->setColor(101, 101, WHITE);
        m_window->drawFramebuffer(m_framebuffer);
    };
}
