#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
    private:
        struct Group {
            std::vector<int> values;
            size_t pairIndex;

            Group() : pairIndex(0) {}
            Group(int v) : pairIndex(0) { values.push_back(v); }
            int key() const { return values.back(); }
        };

        static std::vector<size_t> jacobsthalOrder(size_t pendSize);

        static std::vector<Group> sortGroupsVector(std::vector<Group> groups);
        static std::deque<Group>  sortGroupsDeque(std::deque<Group> groups);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        static std::vector<int> parseInput(int argc, char** argv);

        static std::vector<int> sortWithVector(const std::vector<int>& input);
        static std::vector<int> sortWithDeque(const std::vector<int>& input);
};

#endif