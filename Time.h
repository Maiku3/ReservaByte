#ifndef TIME_H
#define TIME_H

/*
 * Time class
 *
 * This class represents a time with hours and minutes.  It is used by the reservation class
 * to represent the time of a reservation. It has methods that compare the time with another time 
 * and if the time overlaps a time interval. It has a method that adds hours and minutes to the time.
 * It has a static method that validates the time.
 */

class Time
{
public:
  Time(int = 0, int = 0);
  Time(Time &);
  static bool validate(int, int);
  bool lessThan(Time *);
  bool overlaps(Time *, Time *);
  void add(int, int);
  void print();

private:
  int hours;
  int minutes;
  void setTime(int, int);
  int convertToMins();
};

#endif
