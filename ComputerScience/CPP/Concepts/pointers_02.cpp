// Example program
#include <iostream>
#include <string>

int main()
{
    int x;
    int* p1 = &x;             // non-const pointer to non-const int
    const int* p2 = &x;       // non-const pointer to const int
    int* const p3 = &x;       // const pointer to non-const int
    const int* const p4 = &x; // const pointer to const int
    const int* p2a = &x;      // non-const pointer to const int
    int const* p2b = &x;      // non-const pointer to const int

    int y = 10;

    *p1 = 20; // OK
    // *p2 = 20; // Error
    *p3 = 20; // OK
    // *p4 = 20; // Error
    p1 = &y; // OK
    p2 = &y; // OK
    // p3 = &y;  // Error
    // p4 = &y;  // Error

    // *p2a = 20; // Error
    // *p2b = 20; // Error
    p2a = &y; // OK
    p2b = &y; // OK

    return 0;
}
