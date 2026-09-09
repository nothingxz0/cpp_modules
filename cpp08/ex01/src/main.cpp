#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try {
        sp.addNumber(1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::vector<int> data;
    for (int i = 0; i < 10000; ++i)
        data.push_back(std::rand());

    Span big(10000);
    big.addRange(data.begin(), data.end());
    std::cout << big.shortestSpan() << " " << big.longestSpan() << std::endl;

    return 0;
}