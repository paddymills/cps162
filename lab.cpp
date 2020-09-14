// This program demonstrates the the FeetInches class's
// conversion functions.
#include <iostream>
#include <string>
#include "FeetInches.h"
using namespace std;

/*
   Instructions:
      modify FeetInches to overload the following operators:
         - <=
         - >=
         - !=
      and demonstrate ALL overloaded operators
*/

string truthy(bool x)
{
   // returns boolean values as String names
   // instead of binary values

   if (x == 0)
      return "False";
   return "True";
}

int main()
{
   FeetInches dist1 = FeetInches(2, 3);
   FeetInches dist2 = FeetInches(2, 1);

   cout << "-----------------------------------------" << endl;

   // addition/subtraction
   cout << "Addition/Subtraction Operators" << endl;
   cout << dist1 << " + " << dist2 << " = " << dist1 + dist2 << endl;
   cout << dist1 << " - " << dist2 << " = " << dist1 - dist2 << endl;

   cout << "-----------------------------------------" << endl;

   // relational
   cout << "Relational operators" << endl;
   cout << dist1 << " >  " << dist2 << " : " << truthy(dist1 > dist2) << endl;
   cout << dist1 << " <  " << dist2 << " : " << truthy(dist1 < dist2) << endl;
   cout << dist1 << " <= " << dist2 << " : " << truthy(dist1 <= dist2) << endl;
   cout << dist1 << " >= " << dist2 << " : " << truthy(dist1 >= dist2) << endl;
   cout << dist1 << " == " << dist2 << " : " << truthy(dist1 == dist2) << endl;
   cout << dist1 << " != " << dist2 << " : " << truthy(dist1 != dist2) << endl;

   cout << "-----------------------------------------" << endl;

   // prefix/postfix
   cout << "Prefix/Postfix" << endl;
   cout << "++" << dist1 << " :" << endl;
   cout << "\tBefore Call: " << dist1 << endl;
   cout << "\tCall Return: " << ++dist1 << endl;
   cout << "\tAfter Call: " << dist1 << endl;
   cout << dist1 << "++ :" << endl;
   cout << "\tBefore Call: " << dist1 << endl;
   cout << "\tCall Return: " << dist1++ << endl;
   cout << "\tAfter Call: " << dist1 << endl;

   cout << "-----------------------------------------" << endl;

   return 0;
}
