/*
# -------------------- #
# (C)2023 madoodia.com #
# -------------------- #
*/

#include <iostream>

class Test
{
private:
  ~Test() {}
};
int main() { Test t; }             // Error: destructor is private
int main() { Test* t; }            // works fine
int main() { Test* t = new Test; } // works fine