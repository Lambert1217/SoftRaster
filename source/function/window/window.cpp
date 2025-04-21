#include "window.h"

namespace SoftRaster
{
    Window::Window(const std::string &title, uint32_t width, uint32_t height)
        : title_(title), width_(width), height_(height)
    {
        bool init_flag = SDL_Init(SDL_INIT_VIDEO);
        ASSERT(init_flag);
        window_ = SDL_CreateWindow(title.c_str(), width, height, 0);
        ASSERT(window_);
        window_surface_ = SDL_GetWindowSurface(window_);
        ASSERT(window_surface_);
    }

    Window::~Window()
    {
        SDL_DestroyWindow(window_);
        SDL_Quit();
    }

    void Window::drawFramebuffer(const std::shared_ptr<Framebuffer> &framebuffer)
    {
        SDL_BlitSurface(framebuffer->getColorBuffer(), nullptr, window_surface_, nullptr);
        SDL_UpdateWindowSurface(window_);
    }
} // namespace SoftRaster
