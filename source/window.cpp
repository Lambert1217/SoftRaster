#include "window.h"

namespace SoftRaster
{
    window::window(const std::string &title, uint32_t width, uint32_t height)
        : m_title(title), m_width(width), m_height(height)
    {
        bool init_flag = SDL_Init(SDL_INIT_VIDEO);
        ASSERT(init_flag);
        m_window = SDL_CreateWindow(title.c_str(), width, height, 0);
        ASSERT(m_window);
        m_surface = SDL_GetWindowSurface(m_window);
        ASSERT(m_surface);
    }

    window::~window()
    {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }

    void window::drawFramebuffer(const framebuffer &fb)
    {
        SDL_BlitSurface(fb.getColorBuffer(), nullptr, m_surface, nullptr);
        SDL_UpdateWindowSurface(m_window);
    }
} // namespace SoftRaster
