#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    std::string placeholders[5] = {"firstName", "lastName", "nickName", "phoneNumber", "darkestSecret"};
    Contact Contacts[8];
    int     nextContact;
    int     contactCount;
    void    displayAllContacts(); 
    void    displayContact(int Index);
    
public:
    PhoneBook();
    void    addContact();
    void    searchContact();
};

#endif