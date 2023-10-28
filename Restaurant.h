#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "defs.h"
#include "PatronArray.h"
#include "Table.h"
#include "RsvList.h"

/*
 * Restaurant class
 *
 * This class represents a restaurant with a name, a collection of patrons and reservations.
 * It has a constructor that takes a name. It has methods that add a patron, reserve a table,
 * print the reservations, print the reservations of a certain day and print the patrons.
 * It has helper functions to help reserve a table by finding a table that fits the requested capacity and time.
 * It has a method that adds a table to the restaurant.
 */

class Restaurant
{
public:
    Restaurant(string = "Unknown");
    ~Restaurant();
    void addPatron(Patron *);
    void reserveTable(int, int, int, int, int, int, int=0);
    void printReservations();
    void printSchedule(int, int, int);
    void printPatrons();
    void addTable(Table *);
    bool findCapacity(int &, int);
    void findTime(Table **, int, Date *, Time *);

private:
    string name;
    int numTables;
    PatronArray patrons;    
    RsvList reservations;
    Table *tables[MAX_ARR];
};

#endif
