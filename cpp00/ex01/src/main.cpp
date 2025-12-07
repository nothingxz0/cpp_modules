#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook   phoneBook;
    std::string command;
    while (true) {
        std::getline(std::cin, command);
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT") {
            std::cout << "Goodbye !" << std::endl;
            break ;
        }
    }
    return (0);
}