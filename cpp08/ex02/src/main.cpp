#include "MutantStack.hpp"
#include <stack>
#include <iostream>
#include <string>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "sliced stack size: " << s.size() << std::endl;

    MutantStack<std::string> sstack;
    sstack.push("hello");
    sstack.push("world");
    for (MutantStack<std::string>::iterator sit = sstack.begin(); sit != sstack.end(); ++sit)
        std::cout << *sit << std::endl;

    MutantStack<int> empty;
    std::cout << "empty: " << empty.empty() << " size: " << empty.size() << std::endl;

    MutantStack<int> copy(mstack);
    MutantStack<int> assigned;
    assigned = mstack;
    std::cout << "copy size: " << copy.size() << " assigned size: " << assigned.size() << std::endl;

    return 0;
}