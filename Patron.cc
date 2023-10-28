#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Patron.h"

int Patron::NextId = 5001;

Patron::Patron(string n)
{
    name = n;
    id = NextId++;
}

int Patron::getId()
{
    return id;
}

string Patron::getName()
{
    return name;
}

void Patron::print()
{
    cout << "Patron: " << "#" << setw(6) << id << left << setw(12) << name << endl;
}

