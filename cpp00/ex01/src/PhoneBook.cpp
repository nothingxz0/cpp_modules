#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>


PhoneBook::PhoneBook() : nextContact(0), contactCount(0) {}

void  PhoneBook::addContact() {
    std::string line;
    for (int i = 0; i < 5; i++) {
        std::cout << placeholders[i] << " ";
        std::getline(std::cin, line);
        if (!line.empty()) {
            Contacts[nextContact % 8].SetInfos(line, i);
        }
        else
            std::cout << "waaa keteb nechan" << std::endl;
    }
    nextContact++;
    if (contactCount < 8)
        contactCount++;
}

void    PhoneBook::displayAllContacts() {
    // here i should work on the formating  but it does the work for now.
    for (int i = 0; i < contactCount; i++) {
        for(int j = 0; j < 5; j++) {
            std::cout << placeholders[j] << " " << Contacts[i].GetInfo(j) << " ";
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

    displayAllContacts();
    std::cout << "Enter index between 1 and 5: ";
    std::getline(std::cin, line);
    // here should be a check for input.
    index = atoi(line.c_str());
    displayContact(index - 1);
}