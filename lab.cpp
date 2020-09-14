// This program demonstrates the the FeetInches class's
// conversion functions.
#include <iostream>
#include <iomanip>
#include <string>
#include "FeetInches.h"
using namespace std;

/*
   Instructions:
      modify FeetInches to overload the following operators:
         - <=
         - >=
         - !=
      and demonstrate these 3 in a program
*/

string truthy(bool x)
{
   // returns boolean values as String names
   // instead of binary values

   if (x == 0)
      return "False";
   return "True ";
}

void print_line(FeetInches &a, FeetInches &b)
{
   cout << "| " << a << " | " << b << " | ";
   cout << truthy(a <= b) << " | ";
   cout << truthy(a >= b) << " | ";
   cout << truthy(a != b) << " |" << endl;
}

int main()
{
   FeetInches dist1 = FeetInches(2, 3);
   FeetInches dist2 = FeetInches(2, 1);
   FeetInches dist3 = FeetInches(2, 5);
   FeetInches dist4 = FeetInches(3, 1);
   FeetInches dist5 = FeetInches(2, 3);

   // header
   cout << "-----------------------------------------" << endl;
   cout << "|   a   |   b   | a<=b  | a>=b  | a!=b  |" << endl;
   cout << "-----------------------------------------" << endl;

   print_line(dist1, dist2);
   print_line(dist1, dist3);
   print_line(dist1, dist4);
   print_line(dist1, dist5);

   cout << "-----------------------------------------" << endl;
}
