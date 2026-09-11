#include "PmergeMe.hpp"
#include <iostream>
#include <sys/time.h>

static double nowMicroseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> input = PmergeMe::parseInput(argc, argv);

    std::cout << "Before:";
    for (size_t i = 0; i < input.size(); ++i)
        std::cout << " " << input[i];
    std::cout << std::endl;

    double t1 = nowMicroseconds();
    std::vector<int> sortedVec = PmergeMe::sortWithVector(input);
    double t2 = nowMicroseconds();

    double t3 = nowMicroseconds();
    std::vector<int> sortedDeq = PmergeMe::sortWithDeque(input);
    double t4 = nowMicroseconds();

    std::cout << "After:";
    for (size_t i = 0; i < sortedVec.size(); ++i)
        std::cout << " " << sortedVec[i];
    std::cout << std::endl;

    std::cout << "Time to process a range of " << input.size()
               << " elements with std::vector : " << (t2 - t1) << " us" << std::endl;
    std::cout << "Time to process a range of " << input.size()
               << " elements with std::deque : " << (t4 - t3) << " us" << std::endl;

    return 0;
}