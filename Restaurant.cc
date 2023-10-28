#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "Restaurant.h"

Restaurant::Restaurant(string n)
{
    name = n;
    numTables = 0;
}

Restaurant::~Restaurant()
{
    for (int i = 0; i < numTables; i++)
    {
        delete tables[i];
    }
}

void Restaurant::addPatron(Patron *p)
{
    patrons.add(p);
}

void Restaurant::reserveTable(int patronId, int capacity, int year, int month, int day, int hour, int minute)
{
    Patron *p;

    if (!patrons.find(patronId, &p))
    {
        cout << "ERROR: Patron not found" << endl;
        return;
    }
    if (!Date::validate(day, month, year))
    {
        cout << "ERROR: Reservation date ";
        cout << year << "-" << right << setfill('0') << setw(2) << month << "-" << setfill('0') << setw(2) << day;
        cout << " is invalid" << endl;

        return;
    }

    if (!Time::validate(hour, minute))
    {
        cout << "ERROR:  Time: ";
        cout << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << minute;
        cout << " is invalid" << endl;

        return;
    }

    if (hour < OPEN_HR || hour > CLOSE_HR)
    {
        cout << "ERROR: The requested time ";
        Time tempTime(hour, minute);
        tempTime.print();
        cout << " is outside of business hours" << endl;

        return;
    }

    Date *d = new Date(day, month, year);
    Time *t = new Time(hour, minute);

    int targetCapacity = 0;
    if (!findCapacity(targetCapacity, capacity))
    {
        cout << "ERROR: The requested capacity of " << capacity << " cannot be accommodated" << endl;

        delete d;
        delete t;
        return;
    }

    Table *targetTable = NULL;
    findTime(&targetTable, targetCapacity, d, t);

    if (targetTable == NULL)
    {
        cout << "ERROR: No table available found for " << capacity << " people on ";
        d->print();
        cout << " @ ";
        t->print();
        cout << endl;
        delete d;
        delete t;
        return;
    }

    Reservation *r = new Reservation(p, d, t, targetTable);
    reservations.add(r);

    cout << "SUCCESS: Reservation was made" << endl;
}

bool Restaurant::findCapacity(int &targetCap, int requestedCap)
{
    for (int i = 0; i < numTables; i++)
    {
        if (tables[i]->getCapacity() >= requestedCap)
        {
            if (targetCap == 0)
            {
                targetCap = tables[i]->getCapacity();
            }
            else if (tables[i]->getCapacity() < targetCap)
            {
                targetCap = tables[i]->getCapacity();
            }
        }
    }

    if (targetCap == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Restaurant::findTime(Table **targetTable, int targetCap, Date *d, Time *t)
{
    int size;
    Reservation *arr[MAX_ARR];
    reservations.convertToArray(arr, size);

    for (int i = 0; i < numTables; i++)
    {
        if (tables[i]->getCapacity() == targetCap)
        {
            bool overlap = false;
            for (int j = 0; j < size; j++)
            {
                if (arr[j]->matchTable(tables[i]))
                {
                    if (arr[j]->overlaps(d, t))
                    {
                        overlap = true;
                        break;
                    }
                }
            }

            if (!overlap)
            {
                *targetTable = tables[i];
                break;
            }
        }
    }
}

void Restaurant::printSchedule(int year, int month, int day)
{
    int size;
    Reservation *arr[MAX_ARR];
    reservations.convertToArray(arr, size);

    if (!Date::validate(day, month, year))
    {
        cout << "ERROR: Invalid date entered" << endl;
        return;
    }

    Date d(day, month, year);

    cout << "RESERVATIONS FOR ";
    d.print();
    cout << " at " << name << ":" << endl;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]->matchDate(&d))
        {
            arr[i]->print();
        }
    }
}

void Restaurant::printReservations()
{
    cout << "ALL RESERVATIONS AT " << name << ":" << endl;
    reservations.print();
}

void Restaurant::printPatrons()
{
    cout << "PATRONS:" << endl;
    patrons.print();
}

void Restaurant::addTable(Table *t)
{
    tables[numTables] = t;
    numTables++;
}