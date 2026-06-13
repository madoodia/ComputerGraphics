
#include <iostream>

using namespace std;

class MyFriend
{
public:
    static void callMe();
};

class MyClass
{
public:
    virtual void foo() = 0;
    virtual void bar() = 0;
};

class MyDerivedClass : public MyClass
{
public:
    void foo() override;
    void bar() override;

private:
    int x = 10;

    friend class MyFriend;
};

void MyDerivedClass::foo()
{
    cout << "foo" << endl;
}

void MyDerivedClass::bar()
{
    cout << "bar" << endl;
}

MyFriend::callMe()
{
    MyDerivedClass obj;
    obj.foo();
    obj.bar();
    cout << "Calling MyFriend::callMe()" << endl;
    cout << "Accessing MyDerivedClass's private member x: " << obj.x << endl;
}

int main()
{
    MyFriend::callMe();
    return 0;
}
