#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): fixedPointValue(other.fixedPointValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    fixedPointValue = other.fixedPointValue;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return (fixedPointValue);
    std::cout << "getRawBits member function called" << std::endl;
}

void Fixed::setRawBits(int const raw) {
    fixedPointValue = raw;
    std::cout << "setRawBits member function called" << std::endl;
}