// dynamic_cast
#include <iostream>
#include <exception>
using namespace std;

class Base
{
    virtual void dummy() {}
};
class Derived : public Base
{
    int a;
};

int main()
{
    try
    {
        Base* pba = new Derived;
        Base* pbb = new Base;
        Derived* pd;

        pd = dynamic_cast<Derived*>(pba); // pba is a complete object
        if (pd == 0)
            cout << "Null pointer on first type-cast.\n";

        pd = dynamic_cast<Derived*>(pbb); // pbb is not a complete object
        if (pd == 0)
            cout << "Null pointer on second type-cast.\n";

        delete pba;
        delete pbb;
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what();
    }

    return 0;
}