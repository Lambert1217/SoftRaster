#include "timer.h"
#include "base.h"

namespace SoftRaster
{
    Timer::Timer(const std::string &name) : name_(name), is_stopped_(false)
    {
        start_time_point_ = std::chrono::high_resolution_clock::now();
    }

    Timer::~Timer()
    {
        if (!is_stopped_)
        {
            stop();
        }
    }

    void Timer::stop()
    {
        auto end_time_point = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time_point - start_time_point_);

        float delta_time = duration.count() * 0.001f;
        is_stopped_ = true;

        LOG("%s: %.3f ms", name_.c_str(), delta_time);
    }
} // namespace SoftRaster
