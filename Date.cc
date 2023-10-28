#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Date.h"

Date::Date(int d, int m, int y)
{
  setDate(d, m, y);
}

Date::~Date()
{
}

void Date::setDate(int d, int m, int y)
{
  year = ((y > 0) ? y : 0);
  month = ((m > 0 && m <= 12) ? m : 0);
  day = ((d > 0 && d <= lastDayInMonth()) ? d : 0);
}

void Date::print()
{
  cout << year << "-" << right << setfill('0') << setw(2) << month << "-" << setfill('0') << setw(2) << day;
}

bool Date::validate(int d, int m, int y)
{
  if (y < 2023)
    return false;
  if (m < 1 || m > 12)
    return false;

  Date date(d, m, y);
  if (d < 1 || d > date.lastDayInMonth())
    return false;

  return true;
}

bool Date::lessThan(Date *d)
{
  if (year < d->year)
    return true;
  if (year > d->year)
    return false;
  if (month < d->month)
    return true;
  if (month > d->month)
    return false;
  if (day < d->day)
    return true;

  return false;
}

bool Date::equals(Date *d)
{
  if (year == d->year && month == d->month && day == d->day)
    return true;
  else
    return false;
}

int Date::lastDayInMonth()
{
  switch (month)
  {
  case 2:
    if (leapYear())
      return 29;
    else
      return 28;
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    return 31;
  default:
    return 30;
  }
}

bool Date::leapYear()
{
  if (year % 400 == 0 ||
      (year % 4 == 0 && year % 100 != 0))
    return true;
  else
    return false;
}
