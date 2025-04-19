#include "framebuffer.h"

namespace SoftRaster
{
    framebuffer::framebuffer(uint32_t width, uint32_t height)
        : m_width(width), m_height(height), m_pixel_count(width * height)
    {
        ASSERT(m_pixel_count > 0);
        // color
        m_colorbuffer = SDL_CreateSurface(m_width, m_height, SDL_PIXELFORMAT_RGBA8888);
        clearColor({0, 0, 0, 0});
        // depth
        m_depthbuffer.resize(m_pixel_count);
        clearDepth();
    }

    framebuffer::~framebuffer()
    {
        if (m_colorbuffer)
        {
            SDL_DestroySurface(m_colorbuffer);
        }
    }

    void framebuffer::setColor(uint32_t x, uint32_t y, const Color &color)
    {
        ASSERT(x >= 0 && x < m_width && y >= 0 && y < m_height);
        Uint32 *pixels = static_cast<Uint32 *>(m_colorbuffer->pixels);
        Uint32 pixel = SDL_MapRGBA(SDL_GetPixelFormatDetails(m_colorbuffer->format), nullptr, color.r, color.g, color.b, color.a);
        pixels[y * m_width + x] = pixel;
    }

    Color framebuffer::getColor(uint32_t x, uint32_t y) const
    {
        ASSERT(x >= 0 && x < m_width && y >= 0 && y < m_height);
        Uint32 *pixels = static_cast<Uint32 *>(m_colorbuffer->pixels);
        Uint32 pixel = pixels[y * m_width + x];
        Color result;
        SDL_GetRGBA(pixel, SDL_GetPixelFormatDetails(m_colorbuffer->format), nullptr, &result.r, &result.g, &result.b, &result.a);
        return result;
    }

    void framebuffer::setDepth(uint32_t x, uint32_t y, float depth)
    {
        ASSERT(x >= 0 && x < m_width && y >= 0 && y < m_height && depth >= 0 && depth <= 1.0f);
        m_depthbuffer[y * m_width + x] = depth;
    }

    float framebuffer::getDepth(uint32_t x, uint32_t y) const
    {
        ASSERT(x >= 0 && x < m_width && y >= 0 && y < m_height);
        return m_depthbuffer[y * m_width + x];
    }

    void framebuffer::clearColor(const Color &color)
    {
        Uint32 pixel = SDL_MapRGBA(SDL_GetPixelFormatDetails(m_colorbuffer->format), nullptr, color.r, color.g, color.b, color.a);
        Uint32 *pixels = static_cast<Uint32 *>(m_colorbuffer->pixels);
        for (uint32_t i = 0; i < m_pixel_count; ++i)
        {
            pixels[i] = pixel;
        }
    }

    void framebuffer::clearDepth(float depth)
    {
        ASSERT(depth >= 0 && depth <= 1.0f);
        std::fill(m_depthbuffer.begin(), m_depthbuffer.end(), depth);
    }
} // namespace SoftRaster
