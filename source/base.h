/**
 * @file base.h
 * @author 刘亚奇 (1904310303@qq.com)
 * @brief 一些基础功能
 * @date 2025-04-19
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include <SDL3/SDL.h>

// 定义信息日志宏
#define LOG(...) SDL_Log(__VA_ARGS__)
// 定义断言
#define ASSERT(condition) assert(condition)

struct Color
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};