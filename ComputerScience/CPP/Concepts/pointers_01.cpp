// Example program
#include <iostream>
#include <string>

int main()
{
    int* p;
    int x[5] = {10, 20, 30, 40, 50};
    p = x;

    std::cout << "&x: " << p << std::endl;  // &x: 0x505290
    std::cout << "*p: " << *p << std::endl; // *p: 10

    std::cout << "*p++: " << *p++ << std::endl; // *p++: 10
    std::cout << "&x: " << p << std::endl;      // &x: 0x505294

    std::cout << "*++p: " << *++p << std::endl; // *++p: 30
    std::cout << "&x: " << p << std::endl;      // &x: 0x505298

    std::cout << "++*p: " << ++*p << std::endl; // ++*p: 31
    std::cout << "&x: " << p << std::endl;      // &x: 0x505298

    std::cout << "(*p)++: " << (*p)++ << std::endl; // (*p)++: 31
    std::cout << "&x: " << p << std::endl;          // &x: 0x505298

    return 0;
}
