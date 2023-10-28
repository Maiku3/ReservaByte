#include <iostream>
using namespace std;
#include <string>

#include "Control.h"

Control::Control()
{
  restaurant = new Restaurant("Mike's Sushi Restaurant");
}

Control::~Control()
{
  delete restaurant;
}

void Control::initReservations(Restaurant *r)
{
  r->reserveTable(5001, 4, 2023, 5, 13, 12);
  r->reserveTable(5002, 4, 2023, 14, 13, 14, 30);
  r->reserveTable(5002, 4, 2023, 4, 31, 14, 30);

  r->reserveTable(5001, 4, 2023, 5, 13, 17, 30);
  r->reserveTable(5005, 4, 2023, 5, 13, 19, 0);
  r->reserveTable(5002, 2, 2023, 5, 13, 19, 0);
  r->reserveTable(5003, 2, 2023, 5, 13, 19, 0);
  r->reserveTable(5004, 2, 2023, 5, 13, 19, 0);

  r->reserveTable(5006, 4, 2023, 5, 13, 19, 30);
  r->reserveTable(5006, 2, 2023, 5, 13, 18, 30);
  r->reserveTable(5006, 2, 2023, 5, 13, 18, 30);
  r->reserveTable(5006, 8, 2023, 5, 13, 20, 30);
  r->reserveTable(5001, 2, 2023, 5, 13, 20, 30);
  r->reserveTable(5002, 2, 2023, 5, 13, 20, 0);
  r->reserveTable(5004, 4, 2023, 5, 13, 20, 0);
  r->reserveTable(5002, 2, 2023, 5, 13, 21, 0);
  r->reserveTable(5003, 2, 2023, 5, 13, 18, 0);
  r->reserveTable(5003, 2, 2023, 5, 13, 17, 30);

  r->reserveTable(5006, 4, 2023, 5, 14, 19, 15);
  r->reserveTable(5004, 2, 2023, 5, 14, 20, 45);
  r->reserveTable(5003, 4, 2023, 5, 14, 19, 45);
  r->reserveTable(5006, 4, 2023, 5, 14, 18, 0);
  r->reserveTable(5004, 2, 2023, 5, 14, 20, 0);
  r->reserveTable(5004, 2, 2023, 5, 14, 20, 15);
  r->reserveTable(5004, 2, 2023, 5, 14, 20, 30);
  r->reserveTable(5003, 4, 2023, 5, 14, 20, 15);
  r->reserveTable(5004, 2, 2023, 5, 14, 21, 0);
  r->reserveTable(5001, 2, 2023, 5, 14, 20, 30);
  r->reserveTable(5001, 2, 2023, 5, 14, 19, 15);
  r->reserveTable(5001, 4, 2023, 5, 14, 19, 15);
  r->reserveTable(5002, 4, 2023, 5, 14, 19, 0);
  r->reserveTable(5001, 2, 2023, 5, 14, 19, 0);
}

void Control::initTables(Restaurant *r)
{
  r->addTable(new Table(1, 6));
  r->addTable(new Table(2, 4));
  r->addTable(new Table(3, 2));
  r->addTable(new Table(4, 2));
  r->addTable(new Table(5, 4));
  r->addTable(new Table(6, 4));
  r->addTable(new Table(7, 2));
  r->addTable(new Table(8, 2));
  r->addTable(new Table(9, 4));
  r->addTable(new Table(10, 2));
}

void Control::initPatrons(Restaurant *r)
{
  r->addPatron(new Patron("Juliet"));
  r->addPatron(new Patron("Sayid"));
  r->addPatron(new Patron("Jack"));
  r->addPatron(new Patron("Kate"));
  r->addPatron(new Patron("James"));
  r->addPatron(new Patron("Hugo"));
}

void Control::launch()
{
  initTables(restaurant);
  initPatrons(restaurant);
  initReservations(restaurant);

  int choice;
  int year, month, day, hours, minutes;
  int patronId, tableCapacity;

  do
  {
    view.showMenu(choice);
    switch (choice)
    {
    case 1:
      restaurant->printReservations();
      break;
    case 2:
      view.printStr("Please enter the schedule's year, month, day: ");
      view.readInt(year);
      view.readInt(month);
      view.readInt(day);
      restaurant->printSchedule(year, month, day);
      break;
    case 3:
      restaurant->printPatrons();
      break;
    case 4:
      view.printStr("Enter patron id please: ");
      view.readInt(patronId);
      view.printStr("Enter required table capacity please: ");
      view.readInt(tableCapacity);
      view.printStr("Enter reservation year, month, day: ");
      view.readInt(year);
      view.readInt(month);
      view.readInt(day);
      view.printStr("Enter reservation time in hours and minutes: ");
      view.readInt(hours);
      view.readInt(minutes);
      restaurant->reserveTable(patronId, tableCapacity, year, month, day, hours, minutes);
      break;
    default:
      break;
    }
  } while (choice != 0);
}
