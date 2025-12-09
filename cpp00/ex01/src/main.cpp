#include "PhoneBook.hpp"
#include <iostream>
#include <string>
int main() {
    PhoneBook   phoneBook;
    std::string command;

    std::cout << "* HELLO THIS IS PHONEBOOK IT CAN COUNTAIN UP TO 8 CONTACTS *" << std::endl;
    std::cout << "OPTIONS:\nADD: add a contact\nSEARCH: search for a contact\nEXIT: exit..." << std::endl;
    while (true) {
        if (std::cin.eof()) {
            std::cout << "GoodBye!" << std::endl;
            return (1);
        }
        std::cout << "ENTER A COMMAND: " << std::flush;
        if (!std::getline(std::cin, command)) {
            std::cout << "\nGoodBye!" << std::endl;
            return (1);
        }
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