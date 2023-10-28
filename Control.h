#ifndef CONTROL_H
#define CONTROL_H

#include "defs.h"
#include "Restaurant.h"
#include "View.h"
#include "Patron.h"

/*
  * Control class
  * 
  * This class is the controller for the Program.
  * It is responsible for initializing the Restaurant with reservations and patrons on launch.
  * It contains the methods that initialize the Restaurant object with patrons, reservations and tables.
  * It uses the view object to get display output and get the input from the user.
*/

class Control
{
public:
  Control();
  ~Control();
  void launch();

private:
  void initPatrons(Restaurant *);
  void initReservations(Restaurant *);
  void initTables(Restaurant *);
  View view;
  Restaurant *restaurant;
};

#endif
