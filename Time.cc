#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Time.h"

Time::Time(int h, int m)
{
  setTime(h, m);
}

Time::Time(Time &t)
{
  hours = t.hours;
  minutes = t.minutes;
}

void Time::setTime(int h, int m)
{
  hours = (h >= 0 && h < 24) ? h : 0;
  minutes = (m >= 0 && m < 60) ? m : 0;
}

bool Time::validate(int h, int m)
{
  if (h < 0 || h > 23)
    return false;
  if (m < 0 || m > 59)
    return false;

  return true;
}

bool Time::lessThan(Time *t)
{
  if (convertToMins() < t->convertToMins())
    return true;

  return false;
}

int Time::convertToMins()
{
  return (hours * 60 + minutes);
}

bool Time::overlaps(Time *t1, Time *t2)
{
  int t1Mins = t1->convertToMins();
  int t2Mins = t2->convertToMins();
  int thisMins = convertToMins();

  if (thisMins >= t1Mins && thisMins < t2Mins)
    return true;
  else
    return false;
}

void Time::add(int h, int m)
{
  int totalMinutes = convertToMins() + h * 60 + m;
  hours = totalMinutes / 60;
  minutes = totalMinutes % 60;
}
void Time::print()
{
  cout << setfill('0') << setw(2) << hours << ":"
       << setfill('0') << setw(2) << minutes;
}
