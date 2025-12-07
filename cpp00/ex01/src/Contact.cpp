#include "Contact.hpp"
#include <iostream>

void    Contact::SetInfos(std::string Data, int Index) {
    if (Index >= FIRST_NAME && Index <= DARKEST_SECRET)
        Infos[Index] = Data;
    else
        std::cerr << "Out of boundaries" << std::endl;
}

std::string Contact::GetInfo(int Index) {
    if (Index >= FIRST_NAME && Index <= DARKEST_SECRET)
        return (Infos[Index]);
    return ("");
}