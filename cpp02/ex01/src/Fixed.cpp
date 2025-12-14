#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    fixedPointValue = static_cast<int>(value << fractionalBits);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) {
    fixedPointValue = static_cast<int>(roundf(value * (1 << fractionalBits)));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other): fixedPointValue(other.fixedPointValue) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    fixedPointValue = other.fixedPointValue;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

std::ostream& operator<<(std::ostream& cout, const Fixed& obj) {
    cout << obj.toFloat();
    return cout;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (fixedPointValue);
}

void Fixed::setRawBits(int const raw) {
    fixedPointValue = raw;
    std::cout << "setRawBits member function called" << std::endl;
}

int Fixed::toInt(void) const{
    return (fixedPointValue >> fractionalBits);
}

float Fixed::toFloat(void) const {
    return (static_cast<float>(fixedPointValue) / (1 << fractionalBits));
}