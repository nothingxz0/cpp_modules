#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>


template <typename T>
typename T::iterator    easyfind(T& c, int tofind) {
    typename T::iterator  it = std::find(c.begin(), c.end(), tofind);
    if (it == c.end())
        throw std::runtime_error("value not found");
    return it;
}

#endif