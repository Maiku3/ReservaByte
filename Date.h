#ifndef DATE_H
#define DATE_H

/*
 * Date class
 *
 * This class represents a date with the year, month and day.  It is used to represent the date
 * of a reservation. It has methods that compare the date with another date, and prints the date.
 * It has a static method that validates the date, that validates if it is a correct date in 2023 and after.
 */

class Date
{
public:
  Date(int = 0, int = 0, int = 2000);
  ~Date();
  void setDate(int, int, int);
  static bool validate(int, int, int);
  bool lessThan(Date *);
  bool equals(Date *);
  void print();

private:
  int day;
  int month;
  int year;
  int lastDayInMonth();
  bool leapYear();
  string getMonthStr();
};

#endif
