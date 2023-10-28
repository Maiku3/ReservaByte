#include <iostream>
using namespace std;
#include <string>

#include "View.h"

void View::showMenu(int& choice)
{
  int numOptions = 4;

  cout << endl << endl;
  cout << "What would you like to do:"<< endl;
  cout << "  (1) Print reservation schedule" << endl;
  cout << "  (2) Print day schedule" << endl;
  cout << "  (3) Print patrons" << endl;
  cout << "  (4) Reserve a table" << endl;
  cout << "  (0) Exit" << endl<<endl;

  cout << "Enter your selection: ";
  cin >> choice;
  if (choice == 0)
    return;

  while (choice < 0 || choice > numOptions) {
    cout << "Enter your selection: ";
    cin >> choice;
  }

}

void View::printStr(string str)
{
  cout << str;
}

void View::readInt(int& n)
{
  cin >> n;
}

void View::readStr(string& str)
{
  cin >> str;
}



