#include <iostream>
#include "Fixed.hpp"
int main( void ) {
    Fixed a = Fixed(7.5f) / Fixed(2.5f);
    std::cout << a << std::endl;
return 0;
}