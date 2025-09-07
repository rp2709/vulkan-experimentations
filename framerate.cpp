#include "framerate.hpp"

FrameStats::FrameStats(): last(clock::now())
{}

void FrameStats::update()
{
    auto now = clock::now();
    std::chrono::duration<double, std::milli> frame_time = now - last;
    last = now;

    ms = frame_time.count();
    fps = (ms > 0.0) ? 1000.0 / ms : 0.0;

    print();
}

void FrameStats::print() const
{
    // Move cursor to bottom, clear line, then print
    std::cout << "\033[999B"   // move cursor far down
        << "\033[2K"     // clear the entire line
        << "\r";         // move cursor to line start

    std::cout << std::fixed << std::setprecision(2)
        << "Frame time: " << ms << " ms | FPS: " << fps
        << std::flush;

    // Move cursor back up (so program's other prints stay above)
    std::cout << "\033[1A";
}
