#include "iter.hpp"

void print_int(int &i)
{
    std::cout << i;
}

struct Person
{
    std::string name;
    int age;
};

void    print_person(Person &id)
{
    std::cout << id.name << " a " << id.age << " ans." << std::endl;
}

void    increment(int &i)
{
    i += 1;
}

int main(void)
{
    int array[] = {0, 1, 2, 3, 4};
    iter(array, 5, print_int);
    std::cout << std::endl;


    Person Studs[] =  {{"Ychibani", 25}, {"Slatibarfast", 30}, {"Arthur", 35}};
    iter(Studs, 3, print_person);

    iter(array, 5, increment);
    iter(array, 5, print_int);
    iter(array, 0, print_int);
}