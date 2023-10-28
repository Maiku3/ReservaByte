#ifndef RESERVATION_H
#define RESERVATION_H

#include "Date.h"
#include "Time.h"
#include "Patron.h"
#include "defs.h"
#include "Table.h"

/*
 * Reservation class
 *
 * This class represents a reservation with a table, a patron, a date and a time object.
 * It is used by the Restaurant class to store the reservations. It has methods that compare the 
 * reservation with another reservation which compares the dates, times and tables, and prints 
 * the reservation. The matchTable helper function was added to help with Restaurant's reserveTable
 * to match the table it is looking for.
 */

class Reservation
{
public:
    Reservation(Patron *, Date *, Time *, Table *);
    ~Reservation();
    bool lessThan(Reservation *);
    bool overlaps(Date *, Time *);
    bool matchDate(Date *);
    bool matchTable(Table *);
    void print();

private:
    Patron *patron;
    Date *date;
    Time *time;
    Table *table;
};

#endif
