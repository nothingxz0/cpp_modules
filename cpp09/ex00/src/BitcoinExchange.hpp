#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, float> _rates;

        bool isValidDateFormat(const std::string& date) const;
        bool isValidDate(const std::string& date) const;
        bool isValidValue(const std::string& valueStr, float& outValue) const;

    public:
        BitcoinExchange();
        BitcoinExchange(const std::string& dataFile);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void processInputFile(const std::string& inputFile) const;
};

#endif