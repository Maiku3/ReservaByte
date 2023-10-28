#ifndef PATRONARRAY_H
#define PATRONARRAY_H

#define MAX_ARR_SIZE 64

#include "Patron.h"

/*
 * PatronArray class
 *
 * This class represents an collection of Patron objects with a fixed size array of Patron pointers.
 * It is used by the Restaurant class to store a collection of patrons.
 * It has methods that add a patron, find a patron by id, get the size and print the patrons.
 */

class PatronArray
{
public:
  PatronArray();
  ~PatronArray();
  void add(Patron *);
  bool find(int, Patron **);
  void print();

private:
  Patron *elements[MAX_ARR_SIZE];
  int size;
};

#endif
