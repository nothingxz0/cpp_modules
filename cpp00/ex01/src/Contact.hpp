#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
    private:
        std::string Infos[5];
    public:
        enum InfoIndex {
            FIRST_NAME = 0,
            LAST_NAME,
            NICKNAME,
            PHONE_NUMBER,
            DARKEST_SECRET
        };
        void        SetInfos(std::string Data, int Index);
        std::string GetInfo(int Index);
};

#endif