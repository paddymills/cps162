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
      and demonstrate these 3 in a program
*/

string truthy(bool x)
{
   if (x == 0)
      return "False";
   return "True";
}

int main()
{
   FeetInches dist1 = FeetInches(2, 3);
   FeetInches dist2 = FeetInches(2, 1);
   FeetInches dist3 = FeetInches(2, 5);
   FeetInches dist4 = FeetInches(3, 1);
   FeetInches dist5 = FeetInches(2, 3);

   // demonstrate <=
   cout << dist1 << " <= " << dist2 << " is " << truthy(dist1 <= dist2) << endl;
   cout << dist1 << " <= " << dist3 << " is " << truthy(dist1 <= dist3) << endl;
   cout << dist1 << " <= " << dist4 << " is " << truthy(dist1 <= dist4) << endl;
   cout << dist1 << " <= " << dist5 << " is " << truthy(dist1 <= dist5) << endl;

   // demonstrate >=
   cout << dist1 << " >= " << dist2 << " is " << truthy(dist1 >= dist2) << endl;
   cout << dist1 << " >= " << dist3 << " is " << truthy(dist1 >= dist3) << endl;
   cout << dist1 << " >= " << dist4 << " is " << truthy(dist1 >= dist4) << endl;
   cout << dist1 << " >= " << dist5 << " is " << truthy(dist1 >= dist5) << endl;

   // demonstrate !=
   cout << dist1 << " != " << dist2 << " is " << truthy(dist1 != dist2) << endl;
   cout << dist1 << " != " << dist3 << " is " << truthy(dist1 != dist3) << endl;
   cout << dist1 << " != " << dist4 << " is " << truthy(dist1 != dist4) << endl;
   cout << dist1 << " != " << dist5 << " is " << truthy(dist1 != dist5) << endl;
}
