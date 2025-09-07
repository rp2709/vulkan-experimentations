#include "debug.hpp"
#include <iomanip>

void Debug::log(const std::string_view message, const bool flush)
{
    if (not print)return;
    *os << std::setw(indent_size * trace.size())
        << std::setfill(indent_char) << ""
        << message << "\n";
    if (flush)os->flush();
}

void Debug::setIndentChar(const char indent_char) { Debug::indent_char = indent_char; }

void Debug::setIndentSize(const unsigned int indent_size) { Debug::indent_size = indent_size; }

std::ostream& Debug::setOutputStream(std::ostream& os)
{
    std::ostream* old = Debug::os;
    Debug::os = &os;
    return *old;
}

Debug::Step::Step(std::string name):name(std::move(name))
{
    format("Step {} started",this->name);
    start = std::chrono::high_resolution_clock::now();
    trace.push(this->name);
}

Debug::Step::~Step()
{
    const auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::ratio<1,1000>> duration = end - start;
    trace.pop();
    format("Step {} finished in {}", name, duration);
}

bool Debug::disableOutput(bool value)
{
    bool old = print;
    print = not value;
    return old;
}



