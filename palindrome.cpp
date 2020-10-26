#include <iostream>
#include <string>
#include <time.h>

using namespace std;

bool palindromeLoop(string);
bool palindromeRecursive(string, int);

int main()
{
  string testString = "racecarracecarracecarracecarracecar";
  clock_t start;
  clock_t end;

  cout << "looping palindrome" << endl;
  start = clock();
  palindromeLoop(testString);
  end = clock();
  cout << "Loop duration: " << end - start << endl;

  cout << "\n========================\n"
       << endl;

  cout << "recursive palindrome" << endl;
  start = clock();
  palindromeRecursive(testString, 1);
  end = clock();
  cout << "Loop duration: " << end - start << endl;

  return 0;
}

bool palindromeLoop(string s)
{
  for (int i = 0; i < s.length() / 2; i++)
  {
    cout << "\t" << i << ": ";
    cout << s.at(i) << "|" << s.at(s.length() - i - 1) << endl;

    if (s.at(i) != s.at(s.length() - i - 1))
      return false;
  }

  return true;
}
bool palindromeRecursive(string s, int counter)
{
  cout << "\t" << counter << ": " << s << endl;

  if (s.length() < 2)
    return true;

  if (s.at(0) == s.at(s.length() - 1))
    return palindromeRecursive(s.substr(1, s.length() - 2), ++counter);

  return false;
}
