#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void iter(T* arr, const size_t size, F f) {
    for (size_t i = 0; i < size; ++i) {
        f(arr[i]);
    }
}

#endif