#include "Span.hpp"


Span::Span(): maxsize(0) {}

Span::Span(unsigned int n): maxsize(n) {}

Span::Span(const Span& other): maxsize(other.maxsize), v(other.v) {}

Span&    Span::operator=(const Span& other) {
    if (this != &other) {
        maxsize = other.maxsize;
        v = other.v;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (v.size() >= maxsize)
        throw std::runtime_error("Span is full");
    v.push_back(n);
}

int Span::longestSpan()
{
    if (v.size() < 2)
        throw std::runtime_error("not enough elements");
    std::vector<int> sorted(v);
    std::sort(sorted.begin(), sorted.end());
    return sorted.back() - sorted.front();
}

int Span::shortestSpan()
{
    if (v.size() < 2)
        throw std::runtime_error("not enough elements");

    std::vector<int> sorted(v);
    std::sort(sorted.begin(), sorted.end());

    std::vector<int> diffs(sorted.size());
    std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());

    return *std::min_element(diffs.begin() + 1, diffs.end());
}