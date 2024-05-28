// exceptions
#include <iostream>
#include <exception>
using namespace std;

class myexception : public exception
{
    virtual const char* what() const throw()
    {
        return "My exception happened";
    }
} myex;

int main()
{
    try
    {
        throw 20;
    }
    catch (int e)
    {
        cout << "An exception occurred. Exception Nr. " << e << '\n';
    }

    // -----------------

    try
    {
        throw 'a';   // catch char exception
        throw 4;     // catch int exception
        throw "4.3"; // catch default exception
        throw 4.3;   // catch default exception
    }
    catch (int param)
    {
        cout << "int exception \n";
    }
    catch (char param)
    {
        cout << "char exception \n";
    }
    catch (...)
    {
        cout << "default exception \n";
    }

    // -----------------
    try
    {
        throw myex;
    }
    catch (exception& e)
    {
        cout << e.what() << '\n';
    }

    // -----------------
    try
    {
        int* myarray = new int[100000000000000]; // Standard exception: bad allocation
    }
    catch (exception& e)
    {
        cout << "Standard exception: " << e.what() << endl;
    }

    return 0;
}