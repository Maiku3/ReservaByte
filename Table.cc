#include "Table.h"

Table::Table(int n, int c)
{
    number = n;
    capacity = c;
}

int Table::getNumber()
{
    return number;
}

int Table::getCapacity()
{
    return capacity;
}

bool Table::equals(Table *t)
{
    return (number == t->number);
}

