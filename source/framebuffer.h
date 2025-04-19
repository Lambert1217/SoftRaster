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
    class framebuffer
    {
    public:
        framebuffer(uint32_t width, uint32_t height);
        ~framebuffer();

        uint32_t getWidth() const { return m_width; }

        uint32_t getHeight() const { return m_height; }

        void setColor(uint32_t x, uint32_t y, const Color &color);

        Color getColor(uint32_t x, uint32_t y) const;

        void setDepth(uint32_t x, uint32_t y, float depth);

        float getDepth(uint32_t x, uint32_t y) const;

        void clearColor(const Color &c);

        void clearDepth(float depth = 1.0f);

        SDL_Surface *getColorBuffer() const { return m_colorbuffer; }

    private:
        uint32_t m_width, m_height;
        uint32_t m_pixel_count;

        std::vector<float> m_depthbuffer;
        SDL_Surface *m_colorbuffer;
    };
} // namespace SoftRaster
