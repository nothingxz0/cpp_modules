#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

Base* generate(void) {
    int r = rand() % 3;
    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (const std::exception&) {
        /* not an A maybe B? */
    }
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::exception&) {
        /* not an B hmmm then it must be C */
    }
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (const std::exception&) {
        /* if not an C then it's something else */
    }
}

int main(void)
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    for (int i = 0; i < 6; i++)
    {
        Base* p = generate();

        std::cout << "pointer:   ";
        identify(p);

        std::cout << "reference: ";
        identify(*p);

        delete p;
        std::cout << std::endl;
    }
    return (0);
}