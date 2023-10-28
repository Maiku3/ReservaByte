#ifndef TABLE_H
#define TABLE_H

/*
 * Table class
 *
 * This class represents a table with a table number and capacity. It is used by the Restaurant and Reservation class. 
 * It has a function that compare the table with another table to help with reserving a table in the Restaurant class.
 */
 
class Table
{
    public:
        Table(int = 0, int = 0);
        int getNumber();
        int getCapacity();
        bool equals(Table *);

    private: 
        int number;
        int capacity;
};
#endif
