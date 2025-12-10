#include <iostream>
#include <string>

int main() {
    std::string initString = "HI THIS IS BRAIN";
    std::string* stringPTR = &initString;
    std::string &stringREF = initString;

    std::cout << "The value of the string variable: " << initString << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
}