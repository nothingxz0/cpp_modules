#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>


int  main() {
    std::vector<int> v(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(66);
    v.push_back(11);
    v.push_back(35);

    std::vector<int>::iterator it = easyfind(v, 66);
    std::cout << "found: " << *it << std::endl;

    try {
        easyfind(v, 77);
    } catch (std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }

    std::list<int> l;
    l.push_back(6);
    l.push_back(11);

    std::list<int>::iterator lit = easyfind(l, 6);
    std::cout << "found in list: " << *lit << std::endl;

    try {
        easyfind(l, 77);
    } catch (std::exception& e) {
        std::cout << "caught: " << e.what() << std::endl;
    }
    return 0;
}