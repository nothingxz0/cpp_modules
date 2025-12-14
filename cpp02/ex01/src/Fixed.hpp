#ifndef FIXED_H
# define FIXED_H

#include <ostream>

class Fixed {
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        int toInt(void) const;
        float toFloat(void) const;
};

std::ostream& operator<<(std::ostream& cout, const Fixed& obj);

#endif

