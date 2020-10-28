#include <iostream>
#include <string>

using namespace std;

string findCapsRec(string);
string findCapsNonRec(string);

int main()
{
  string test("I lOVe PrOgraMMiNg in C++");

  string res = findCapsRec(test);
  cout << "capitals: " << res << endl;

  return 0;
}

string findCapsRec(string s)
{
  string result;

  // get first character
  char c = s.front();

  // ascii range for uppercase is 65 - 90 (inclusive)
  // if out of range, set to null
  if (c < 65 || c > 90)
    c = 0;

  result.push_back(c);
  if (s.length() > 1)
    result.append(findCapsRec(s.substr(1, s.length() - 1)));

  return result;
}