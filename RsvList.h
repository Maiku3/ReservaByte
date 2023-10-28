#ifndef RSVLIST_H
#define RSVLIST_H

#include "defs.h"
#include "Reservation.h"

/*
 * RsvList class
 *
 * This class represents a collection of Reservations as a linked list. 
 * It is used by the Restaurant class to store the reservations. 
 * It has methods to add and print the reservations. It has a function that 
 * converts the linked list to an array to make reserving a table possible in 
 * the Restaurant Class. 
 */

class RsvList
{
    class Node
    {
    public:
        Reservation *data;
        Node *next;
    };

public:
    RsvList();
    ~RsvList();
    void add(Reservation *r);
    void convertToArray(Reservation **arr, int &size);
    void print();

private:
    Node *head;
};

#endif
