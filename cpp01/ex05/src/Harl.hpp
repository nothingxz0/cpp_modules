#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl {
    private:
        std::string levels[4];
        void    debug(void);
        void    info( void );
        void    warning( void );
        void    error( void );
    public:
        Harl();
        void complain(std::string level);
};

#endif