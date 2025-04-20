/**
 * @file framebuffer.h
 * @author 刘亚奇 (1904310303@qq.com)
 * @brief 帧缓冲
 * @date 2025-04-19
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include "base.h"
#include "SDL3/SDL.h"

namespace SoftRaster
{
    class Framebuffer
    {
    public:
        Framebuffer(uint32_t width, uint32_t height);
        ~Framebuffer();

        uint32_t getWidth() const { return width_; }

        uint32_t getHeight() const { return height_; }

        void setColor(uint32_t x, uint32_t y, const Color &color);

        Color getColor(uint32_t x, uint32_t y) const;

        void setDepth(uint32_t x, uint32_t y, float depth);

        float getDepth(uint32_t x, uint32_t y) const;

        void clearColor(const Color &c);

        void clearDepth(float depth = 1.0f);

        SDL_Surface *getColorBuffer() const { return colorbuffer_; }

    private:
        uint32_t width_, height_;
        uint32_t pixel_count_;

        std::vector<float> depthbuffer_;
        SDL_Surface *colorbuffer_;
    };
} // namespace SoftRaster
