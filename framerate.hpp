#pragma once
#include <chrono>
#include <iostream>


class FrameStats {
public:
    FrameStats();

    void update();

private:
    using clock = std::chrono::high_resolution_clock;
    std::chrono::time_point<clock> last;
    double ms = 0.0;
    double fps = 0.0;

    void print() const;
};
