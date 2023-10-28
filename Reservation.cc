#include <iostream>
#include <iomanip>
using namespace std;

#include "Reservation.h"
#include "Table.h"

Reservation::Reservation(Patron *p, Date *d, Time *t, Table *tbl)
{
    patron = p;
    date = d;
    time = t;
    table = tbl;
}

Reservation::~Reservation()
{
    delete date;
    delete time;
}

bool Reservation::lessThan(Reservation *r)
{
    if (date->lessThan(r->date))
        return true;
    else if (date->equals(r->date))
        return time->lessThan(r->time);
    else
        return false;
}

bool Reservation::matchDate(Date *d)
{
    return date->equals(d);
}

bool Reservation::overlaps(Date *d, Time *t)
{
    if (!date->equals(d))
        return false;

    Time *end = new Time(*time);
    end->add(2, 0);

    Time *end2 = new Time(*t);
    end2->add(2, 0);

    if (time->overlaps(t, end2) || t->overlaps(time, end))
    {
    	delete end;
    	delete end2;
        return true;
    }
        
    delete end;
    delete end2;
    return false;
}

bool Reservation::matchTable(Table *tbl)
{
    return table->equals(tbl);
}

void Reservation::print()
{
    if (patron == NULL)
    {
        cout << "ERROR: Patron is NULL" << endl;
        return;
    }

    date->print();
    cout << " @ ";
    time->print();
    cout << setfill(' ') << " ==> "
         << "Table " << right << setw(2) << table->getNumber() << " " << left << setw(12) << patron->getName() << endl;
}
