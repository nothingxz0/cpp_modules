#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& dataFile) {
    std::ifstream file(dataFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;
        std::string date = line.substr(0, pos);
        std::string rateStr = line.substr(pos + 1);

        std::stringstream ss(rateStr);
        float rate;
        ss >> rate;

        _rates[date] = rate;
    }
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        _rates = other._rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDateFormat(const std::string& date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); i++) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (!isValidDateFormat(date))
        return false;

    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    (void)year;

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (isLeap)
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& outValue) const {
    if (valueStr.empty())
        return false;

    std::stringstream ss(valueStr);
    ss >> outValue;

    if (ss.fail())
        return false;

    std::string leftover;
    ss >> leftover;
    if (!leftover.empty())
        return false;

    return true;
}

void BitcoinExchange::processInputFile(const std::string& inputFile) const {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        size_t sep = line.find(" | ");
        if (sep == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, sep);
        std::string valueStr = line.substr(sep + 3);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        float value;
        if (!isValidValue(valueStr, value)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        if (_rates.empty()) {
            std::cerr << "Error: no database loaded." << std::endl;
            continue;
        }

        std::map<std::string, float>::const_iterator it = _rates.lower_bound(date);
        if (it == _rates.end() || it->first != date) {
            if (it == _rates.begin()) {
                std::cerr << "Error: no rate available for date => " << date << std::endl;
                continue;
            }
            --it;
        }

        std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
    }
    file.close();
}