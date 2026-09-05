#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printAny(T const& x) {
    std::cout << x << std::endl;
}

static void printInt(int const &i) {
    std::cout << i << std::endl;
}

static void printString(std::string const &s) {
    std::cout << s << std::endl;
}

static void addOne(int &i) {
    i += 1;
}

int main( void ) {
    int arr[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    iter(arr, size, printInt);
    iter(arr, size, addOne);
    iter(arr, size, printInt);

    std::string strings[] = {"Soufine", "NOTHING", "!"};
    size_t string_size = sizeof(strings) / sizeof(strings[0]);

    iter(strings, string_size, printString);

    iter(arr, size, printAny<int>);
    iter(strings, string_size, printAny<std::string>);

    return 0;
}