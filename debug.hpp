#pragma once

#include <chrono>
#include <format>
#include <iostream>
#include <stack>
#include <string>

class Debug
{
    public:

    static void log(std::string_view message, bool flush = false);

    template<class... Args>
    static void format(std::format_string<Args...> format_string, Args&&... args)
    {
        log(std::format(format_string, std::forward<Args>(args)...));
    }

    static void setIndentSize(unsigned int indent_size);
    static void setIndentChar(char indent_char);
    static std::ostream& setOutputStream(std::ostream& os);

    class Step
    {
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
        std::string name;
    public:
        explicit Step(std::string name);
        ~Step();
    };

private:
    static inline char indent_char = ' ';
    static inline unsigned indent_size = 4;
    static inline std::ostream* os = &std::cout;
    static inline std::stack<std::string> trace;
};