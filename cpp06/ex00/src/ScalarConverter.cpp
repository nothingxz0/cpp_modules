#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <cerrno>

enum e_type { CHAR, INT, FLOAT, DOUBLE, PSEUDO, INVALID };

static bool allDigits(const std::string& s)
{
    if (s.empty())
        return (false);
    for (size_t i = 0; i < s.length(); i++)
    {
        if (!std::isdigit(s[i]))
            return (false);
    }
    return (true);
}

static bool isDouble(const std::string& s)
{
    size_t start = 0;

    if (s[0] == '+' || s[0] == '-')
        start = 1;
    size_t dot = s.find('.');
    if (dot == std::string::npos)
        return (false);
    std::string before = s.substr(start, dot - start);
    std::string after = s.substr(dot + 1);

    return (allDigits(before) && allDigits(after));
}

static bool isFloat(const std::string& s)
{
    if (s[s.length() - 1] != 'f')
        return (false);
    return (isDouble(s.substr(0, s.length() - 1)));
}

static bool isInt(const std::string& s)
{
    size_t start = 0;

    if (s[0] == '+' || s[0] == '-')
        start = 1;
    return (allDigits(s.substr(start)));
}

static bool isPseudo(const std::string& s)
{
    return (s == "+inf" || s == "-inf" || s == "nan"
        || s == "+inff" || s == "-inff" || s == "nanf");
}

static e_type getType(const std::string& s)
{
    if (isPseudo(s))
        return (PSEUDO);
    else if (s.length() == 1 && !std::isdigit(s[0]))
        return (CHAR);
    else if (isInt(s))
        return (INT);
    else if (isFloat(s))
        return (FLOAT);
    else if (isDouble(s))
        return (DOUBLE);
    return (INVALID);
}

static void printPseudo(const std::string& s)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (s == "-inf" || s == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
    else if (s == "nan" || s == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
}

static void printChar(double value)
{
    if (value < 0 || value > 127) {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    if (!std::isprint(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double value) {
    if (value < std::numeric_limits<int>::min()
        || value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void printFloat(double value) {
    if (value < -std::numeric_limits<float>::max()
        || value > std::numeric_limits<float>::max())
    {
        std::cout << "float: impossible" << std::endl;
        return;
    }

    float f = static_cast<float>(value);
    std::streamsize prec = std::cout.precision();

    std::cout << "float: ";
    if (f == std::floor(f))
        std::cout << std::fixed << std::setprecision(1);
    std::cout << f << "f" << std::endl;
    std::cout.unsetf(std::ios::floatfield);
    std::cout.precision(prec);
}

static void printDouble(double value) {
    std::streamsize prec = std::cout.precision();

    std::cout << "double: ";
    if (value == std::floor(value))
        std::cout << std::fixed << std::setprecision(1);
    std::cout << value << std::endl;
    std::cout.unsetf(std::ios::floatfield);
    std::cout.precision(prec);
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal)
{
    double value;
    e_type type;

    if (literal.empty()) {
        std::cerr << "Error: empty input." << std::endl;
        return;
    }

    type = getType(literal);

    if (type == INVALID) {
        std::cerr << "Error: invalid input." << std::endl;
        return;
    }
    if (type == PSEUDO) {
        printPseudo(literal);
        return;
    }

    if (type == CHAR)
        value = static_cast<double>(literal[0]);
    else {
        errno = 0;
        value = std::strtod(literal.c_str(), NULL);
        if (errno == ERANGE) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}