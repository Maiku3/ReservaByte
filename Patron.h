#ifndef PATRON_H
#define PATRON_H

/*
 * Patron class
 *
 * This class represents a patron with a name and an id. It is used by the Restaurant class to store
 * the patrons. It has methods that get the id and name and print the patron.
 * It has a static variable NextId that is used to give the id for each new patron.
 */

class Patron
{
public:
    Patron(string = "Unknown");
    int getId();
    string getName();
    void print();

private:
    static int NextId;
    string name;
    int id;
};

#endif
