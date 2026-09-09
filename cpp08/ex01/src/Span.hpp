#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
private:
    unsigned int maxsize;
    std::vector<int> v;
public:
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int n);
    int shortestSpan();
    int longestSpan();

    template <typename InputIterator>
    void addRange(InputIterator begin, InputIterator end) {
        if (std::distance(begin, end) + v.size() > maxsize)
            throw std::runtime_error("Span is full");
        v.insert(v.end(), begin, end);
    }
};

#endif