#include "framebuffer.h"

namespace SoftRaster
{
    Framebuffer::Framebuffer(uint32_t width, uint32_t height)
        : width_(width), height_(height), pixel_count_(width * height)
    {
        ASSERT(pixel_count_ > 0);
        // color
        colorbuffer_ = SDL_CreateSurface(width_, height_, SDL_PIXELFORMAT_RGBA8888);
        clearColor({0, 0, 0, 0});
        // depth
        depthbuffer_.resize(pixel_count_);
        clearDepth();
    }

    Framebuffer::~Framebuffer()
    {
        if (colorbuffer_)
        {
            SDL_DestroySurface(colorbuffer_);
        }
    }

    void Framebuffer::setColor(uint32_t x, uint32_t y, const Color &color)
    {
        ASSERT(x >= 0 && x < width_ && y >= 0 && y < height_);
        Uint32 *pixels = static_cast<Uint32 *>(colorbuffer_->pixels);
        Uint32 pixel = SDL_MapRGBA(SDL_GetPixelFormatDetails(colorbuffer_->format), nullptr, color.r, color.g, color.b, color.a);
        pixels[y * width_ + x] = pixel;
    }

    Color Framebuffer::getColor(uint32_t x, uint32_t y) const
    {
        ASSERT(x >= 0 && x < width_ && y >= 0 && y < height_);
        Uint32 *pixels = static_cast<Uint32 *>(colorbuffer_->pixels);
        Uint32 pixel = pixels[y * width_ + x];
        Color result;
        SDL_GetRGBA(pixel, SDL_GetPixelFormatDetails(colorbuffer_->format), nullptr, &result.r, &result.g, &result.b, &result.a);
        return result;
    }

    void Framebuffer::setDepth(uint32_t x, uint32_t y, float depth)
    {
        ASSERT(x >= 0 && x < width_ && y >= 0 && y < height_ && depth >= 0 && depth <= 1.0f);
        depthbuffer_[y * width_ + x] = depth;
    }

    float Framebuffer::getDepth(uint32_t x, uint32_t y) const
    {
        ASSERT(x >= 0 && x < width_ && y >= 0 && y < height_);
        return depthbuffer_[y * width_ + x];
    }

    void Framebuffer::clearColor(const Color &color)
    {
        Uint32 pixel = SDL_MapRGBA(SDL_GetPixelFormatDetails(colorbuffer_->format), nullptr, color.r, color.g, color.b, color.a);
        Uint32 *pixels = static_cast<Uint32 *>(colorbuffer_->pixels);
        for (uint32_t i = 0; i < pixel_count_; ++i)
        {
            pixels[i] = pixel;
        }
    }

    void Framebuffer::clearDepth(float depth)
    {
        ASSERT(depth >= 0 && depth <= 1.0f);
        std::fill(depthbuffer_.begin(), depthbuffer_.end(), depth);
    }
} // namespace SoftRaster
