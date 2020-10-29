/*
  Patrick Miller
  Nyhoff Chapter 10 - lab
*/

#include <iostream>
#include <string>

using namespace std;

string findCapsRec(string);
string findCapsNonRec(string);

int main()
{
  string test("I lOVe PrOgraMMiNg in C++");

  cout << "capitals (rec): " << findCapsRec(test) << endl;
  cout << "capitals (non-rec): " << findCapsNonRec(test) << endl;

  return 0;
}

string findCapsRec(string s)
{
  string result;

  // ascii range for uppercase is 65 - 90 (inclusive)
  if (s[0] >= 65 && s[0] <= 90)
    result.push_back(s[0]);

  // recursive call if not at end of string
  if (s.length() > 1)
    result.append(findCapsRec(s.substr(1, s.length() - 1)));

  return result;
}

string findCapsNonRec(string s)
{
  string result; // return string
  char c;        // current character

  for (int i = 0; i < s.length(); i++)
  {
    char c = s[i];

    // ascii range for uppercase is 65 - 90 (inclusive)
    if (c >= 65 && c <= 90)
      result.push_back(c);
  }

  return result;
}