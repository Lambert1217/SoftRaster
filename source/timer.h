/**
 * @file timer.h
 * @author 刘亚奇 (1904310303@qq.com)
 * @brief 计时器
 * @date 2025-04-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

namespace SoftRaster
{
    class Timer
    {
    public:
        Timer(const std::string &name);
        ~Timer();

        void stop();

    private:
        std::string name_;
        std::chrono::steady_clock::time_point start_time_point_;
        bool is_stopped_;
    };
} // namespace SoftRaster

#define PROFILE_SCOPE(name) SoftRaster::Timer timer##__LINE__(name)