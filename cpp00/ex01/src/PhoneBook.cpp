#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>


PhoneBook::PhoneBook() : nextContact(0), contactCount(0) {}

void  PhoneBook::addContact() {
    std::string line;
    for (int i = 0; i < 5; i++) {
        while (true) {
            std::cout << placeholders[i] << " ";
            if (!std::getline(std::cin, line)) {
                std::cout << "\nEOF detected. Exiting contact creation." << std::endl;
                return;
            }
            if (line.empty()) {
                std::cout << "waaa keteb nechan" << std::endl;
                continue;
            }
            if (i == 3) {
                bool isValid = true;
                for (size_t j = 0; j < line.length(); j++) {
                    if (!isdigit(line[j])) {
                        isValid = false;
                        break;
                    }
                }
                if (!isValid) {
                    std::cout << "Phone number must contain only digits." << std::endl;
                    continue;
                }
            }
            Contacts[nextContact % 8].SetInfos(line, i);
            break;
        }
    }
    nextContact++;
    if (contactCount < 8)
        contactCount++;
}

void    PhoneBook::displayAllContacts() {
    std::string field;
    
    std::cout << std::setw(10) << std::right << "Index" << "|";
    std::cout << std::setw(10) << std::right << "First Name" << "|";
    std::cout << std::setw(10) << std::right << "Last Name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << std::endl;
    
    for (int i = 0; i < contactCount; i++) {
        std::cout << std::setw(10) << std::right << i + 1 << "|";
        for(int j = 0; j < 3; j++) {
            field = Contacts[i].GetInfo(j);
            if (field.length() > 10) {
                field = field.substr(0, 9) + ".";
            }
            std::cout << std::setw(10) << std::right << field << "|";
        }
        std::cout << std::endl;
    }
}

void    PhoneBook::displayContact(int Index) {
    for (int i = 0; i < 5; i++) {
        std::cout << placeholders[i] << " " << Contacts[Index].GetInfo(i) << " ";
    }
    std::cout << std::endl;
}

void    PhoneBook::searchContact() {
    std::string line;
    int index;

    if (contactCount == 0) {
        std::cout << "No contacts available." << std::endl;
        return;
    }
    
    displayAllContacts();
    std::cout << "Enter index: ";
    if (!std::getline(std::cin, line)) {
        std::cout << "\nEOF detected." << std::endl;
        return;
    }
    
    bool isValidNumber = !line.empty();
    for (size_t i = 0; i < line.length(); i++) {
        if (!isdigit(line[i])) {
            isValidNumber = false;
            break;
        }
    }
    
    if (!isValidNumber) {
        std::cout << "Invalid input. Please enter a valid number." << std::endl;
        return;
    }
    
    index = atoi(line.c_str());
    
    if (index < 1 || index > contactCount) {
        std::cout << "Invalid index. Please enter a number between 1 and " << contactCount << "." << std::endl;
        return;
    }
    
    displayContact(index - 1);
}