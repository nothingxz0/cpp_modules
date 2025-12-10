#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl() {
    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";
}

void    Harl::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void    Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level) {
    void (Harl::*actions[4])();
    actions[0] = &Harl::debug;
    actions[1] = &Harl::info;
    actions[2] = &Harl::warning;
    actions[3] = &Harl::error;
    int i = 0;
    while (levels[i] != level)
        i++;
    switch (i)
    {
    case 0:
        (this->*actions[0])();
        break;
    case 1:
        (this->*actions[1])();
        break;
    case 2:
        (this->*actions[2])();
        break;
    case 3:
        (this->*actions[3])();
        break;
    default:
        std::cout << "Invalid level !" <<  std::endl;
        break;
    }
}