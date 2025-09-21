// Example program
#include <iostream>
#include <string>
#include <vector>

class Base
{
public:
    Base() {}
    ~Base() {}

    unsigned int id;
    std::string name;
};

class Derived : public Base
{
public:
    Derived() {}
    ~Derived() {}

    void createList();

    unsigned int age;
    std::string address;

    std::vector<Base*> m_targetList;
};

const unsigned int total = 100;

unsigned int counter = 0;

Base* objects[total];
unsigned int numberOfTeams = 3;
unsigned int numberOfMinesPerTeam = 5;

void Derived::createList()
{
    m_targetList.clear();

    for (unsigned int i = 0; i < counter; i++)
    {
        Base* target = objects[i];
        if (target == nullptr || target == this)
            continue;
        m_targetList.push_back(target);
    }
}

int main()
{

    for (unsigned int i = 0; i < numberOfTeams; i++)
    {
        for (unsigned int j = 0; j < numberOfMinesPerTeam; j++)
        {
            objects[counter] = new Derived();
            objects[counter]->id = counter;
            objects[counter]->name = "Mine";
            static_cast<Derived*>(objects[counter])->age = 10;
            static_cast<Derived*>(objects[counter])->address = "Tehran";
            counter++;
        }
    }

    int index = 1;
    
	Derived* d = static_cast<Derived*>(objects[index]);
    d->createList();

	delete objects[index];
	index++;


    return 0;
}
