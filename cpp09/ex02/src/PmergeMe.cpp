#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cerrno>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }
PmergeMe::~PmergeMe() {}

std::vector<size_t> PmergeMe::jacobsthalOrder(size_t pendSize) {
    std::vector<size_t> order;
    if (pendSize == 0)
        return order;

    size_t maxIndex = pendSize + 1;
    long jPrev2 = 0, jPrev1 = 1;
    size_t prevBound = 1;

    while (prevBound < maxIndex) {
        long j = jPrev1 + 2 * jPrev2;
        jPrev2 = jPrev1;
        jPrev1 = j;

        size_t upper = (static_cast<size_t>(j) < maxIndex) ? static_cast<size_t>(j) : maxIndex;
        if (upper > prevBound) {
            for (size_t b = upper; b > prevBound; --b)
                order.push_back(b - 2);
            prevBound = upper;
        }
    }
    return order;
}

std::vector<PmergeMe::Group> PmergeMe::sortGroupsVector(std::vector<Group> groups) {
    if (groups.size() <= 1)
        return groups;

    bool hasStray = false;
    Group stray;
    if (groups.size() % 2 == 1) {
        hasStray = true;
        stray = groups.back();
        groups.pop_back();
    }

    size_t pairCount = groups.size() / 2;
    std::vector<Group> bGroups(pairCount);
    std::vector<Group> aGroups(pairCount);

    for (size_t i = 0; i < pairCount; ++i) {
        Group& g1 = groups[2 * i];
        Group& g2 = groups[2 * i + 1];
        if (g1.key() < g2.key()) {
            bGroups[i] = g1;
            aGroups[i] = g2;
        } else {
            bGroups[i] = g2;
            aGroups[i] = g1;
        }
        aGroups[i].pairIndex = i;
    }

    std::vector<Group> sortedA = sortGroupsVector(aGroups);

    std::vector<Group> mainChain;
    mainChain.push_back(bGroups[sortedA[0].pairIndex]);
    for (size_t i = 0; i < sortedA.size(); ++i)
        mainChain.push_back(sortedA[i]);

    std::vector<Group> pend;
    for (size_t i = 1; i < sortedA.size(); ++i)
        pend.push_back(bGroups[sortedA[i].pairIndex]);
    if (hasStray)
        pend.push_back(stray);

    std::vector<size_t> order = jacobsthalOrder(pend.size());

    for (size_t idx = 0; idx < order.size(); ++idx) {
        size_t pendIdx = order[idx];
        Group toInsert = pend[pendIdx];
        bool isStray = (hasStray && pendIdx == pend.size() - 1);

        size_t searchEnd;
        if (isStray) {
            searchEnd = mainChain.size();
        } else {
            int boundKey = sortedA[pendIdx + 1].key();
            size_t lo = 0, hi = mainChain.size();
            while (lo < hi) {
                size_t mid = (lo + hi) / 2;
                if (mainChain[mid].key() < boundKey)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            searchEnd = lo;
        }

        size_t lo = 0, hi = searchEnd;
        while (lo < hi) {
            size_t mid = (lo + hi) / 2;
            if (mainChain[mid].key() < toInsert.key())
                lo = mid + 1;
            else
                hi = mid;
        }
        mainChain.insert(mainChain.begin() + lo, toInsert);
    }

    return mainChain;
}

std::vector<int> PmergeMe::sortWithVector(const std::vector<int>& input) {
    std::vector<Group> groups;
    for (size_t i = 0; i < input.size(); ++i)
        groups.push_back(Group(input[i]));

    std::vector<Group> sorted = sortGroupsVector(groups);

    std::vector<int> result;
    for (size_t i = 0; i < sorted.size(); ++i)
        for (size_t j = 0; j < sorted[i].values.size(); ++j)
            result.push_back(sorted[i].values[j]);
    return result;
}

std::deque<PmergeMe::Group> PmergeMe::sortGroupsDeque(std::deque<Group> groups) {
    if (groups.size() <= 1)
        return groups;

    bool hasStray = false;
    Group stray;
    if (groups.size() % 2 == 1) {
        hasStray = true;
        stray = groups.back();
        groups.pop_back();
    }

    size_t pairCount = groups.size() / 2;
    std::deque<Group> bGroups(pairCount);
    std::deque<Group> aGroups(pairCount);

    for (size_t i = 0; i < pairCount; ++i) {
        Group& g1 = groups[2 * i];
        Group& g2 = groups[2 * i + 1];
        if (g1.key() < g2.key()) {
            bGroups[i] = g1;
            aGroups[i] = g2;
        } else {
            bGroups[i] = g2;
            aGroups[i] = g1;
        }
        aGroups[i].pairIndex = i;
    }

    std::deque<Group> sortedA = sortGroupsDeque(aGroups);

    std::deque<Group> mainChain;
    mainChain.push_back(bGroups[sortedA[0].pairIndex]);
    for (size_t i = 0; i < sortedA.size(); ++i)
        mainChain.push_back(sortedA[i]);

    std::deque<Group> pend;
    for (size_t i = 1; i < sortedA.size(); ++i)
        pend.push_back(bGroups[sortedA[i].pairIndex]);
    if (hasStray)
        pend.push_back(stray);

    std::vector<size_t> order = jacobsthalOrder(pend.size());

    for (size_t idx = 0; idx < order.size(); ++idx) {
        size_t pendIdx = order[idx];
        Group toInsert = pend[pendIdx];
        bool isStray = (hasStray && pendIdx == pend.size() - 1);

        size_t searchEnd;
        if (isStray) {
            searchEnd = mainChain.size();
        } else {
            int boundKey = sortedA[pendIdx + 1].key();
            size_t lo = 0, hi = mainChain.size();
            while (lo < hi) {
                size_t mid = (lo + hi) / 2;
                if (mainChain[mid].key() < boundKey)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            searchEnd = lo;
        }

        size_t lo = 0, hi = searchEnd;
        while (lo < hi) {
            size_t mid = (lo + hi) / 2;
            if (mainChain[mid].key() < toInsert.key())
                lo = mid + 1;
            else
                hi = mid;
        }
        mainChain.insert(mainChain.begin() + lo, toInsert);
    }

    return mainChain;
}

std::vector<int> PmergeMe::sortWithDeque(const std::vector<int>& input) {
    std::deque<Group> groups;
    for (size_t i = 0; i < input.size(); ++i)
        groups.push_back(Group(input[i]));

    std::deque<Group> sorted = sortGroupsDeque(groups);

    std::vector<int> result;
    for (size_t i = 0; i < sorted.size(); ++i)
        for (size_t j = 0; j < sorted[i].values.size(); ++j)
            result.push_back(sorted[i].values[j]);
    return result;
}

std::vector<int> PmergeMe::parseInput(int argc, char** argv) {
    std::vector<int> result;

    for (int i = 1; i < argc; ++i) {
        std::string s(argv[i]);
        if (s.empty()) {
            std::cerr << "Error" << std::endl;
            std::exit(1);
        }
        for (size_t j = 0; j < s.size(); ++j) {
            if (!isdigit(static_cast<unsigned char>(s[j]))) {
                std::cerr << "Error" << std::endl;
                std::exit(1);
            }
        }
        errno = 0;
        char* endptr;
        long val = std::strtol(s.c_str(), &endptr, 10);
        if (errno == ERANGE || val > INT_MAX || val <= 0) {
            std::cerr << "Error" << std::endl;
            std::exit(1);
        }
        result.push_back(static_cast<int>(val));
    }
    return result;
}