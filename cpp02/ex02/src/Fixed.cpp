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

bool Fixed::operator>(const Fixed& other) const {
    if (this->getRawBits() > other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed& other) const {
    if (this->getRawBits() < other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed& other) const {
    if (this->getRawBits() >= other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed& other) const {
    if (this->getRawBits() <= other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed& other) const {
    if (this->getRawBits() == other.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed& other) const {
    if (this->getRawBits() != other.getRawBits())
        return (true);
    return (false);
}

Fixed    Fixed::operator+(const Fixed& other) const{
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return (result);
}

Fixed    Fixed::operator-(const Fixed& other) const{
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return (result);
}

Fixed    Fixed::operator*(const Fixed& other) const{
    Fixed result;
    result.setRawBits(this->getRawBits() * (other.getRawBits() >> fractionalBits));
    return (result);
}

Fixed    Fixed::operator/(const Fixed& other) const{
    Fixed result;
    result.setRawBits(this->getRawBits() / (other.getRawBits() << fractionalBits));
    return (result);
}

Fixed& Fixed::operator++(){
    fixedPointValue++;
    return (*this);
}

Fixed Fixed::operator++(int){
    Fixed old(*this);
    fixedPointValue++;
    return (old);
}

Fixed& Fixed::min(Fixed& first, Fixed& second) {
    if (first < second)
        return first;
    return second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second) {
    if (first < second)
        return first;
    return second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second) {
    if (first > second)
        return first;
    return second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second) {
    if (first > second)
        return first;
    return second;
}