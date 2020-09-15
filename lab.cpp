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
   FeetInches dist1(2, 3);
   FeetInches dist2(2, 3);
   FeetInches dist3(1, 8);
   FeetInches dist4(3, 5);

   cout << "-----------------------" << endl;

   // less-than or equal to
   cout << dist1 << " <= " << dist2 << " : " << truthy(dist1 <= dist2) << endl;
   cout << dist1 << " <= " << dist3 << " : " << truthy(dist1 <= dist3) << endl;
   cout << dist1 << " <= " << dist4 << " : " << truthy(dist1 <= dist4) << endl;

   cout << "-----------------------" << endl;

   // greater-than or equal to
   cout << dist1 << " >= " << dist2 << " : " << truthy(dist1 >= dist2) << endl;
   cout << dist1 << " >= " << dist3 << " : " << truthy(dist1 >= dist3) << endl;
   cout << dist1 << " >= " << dist4 << " : " << truthy(dist1 >= dist4) << endl;

   cout << "-----------------------" << endl;

   // not equal
   cout << dist1 << " != " << dist2 << " : " << truthy(dist1 != dist2) << endl;
   cout << dist1 << " != " << dist3 << " : " << truthy(dist1 != dist3) << endl;
   cout << dist1 << " != " << dist4 << " : " << truthy(dist1 != dist4) << endl;

   cout << "-----------------------" << endl;

   return 0;
}
