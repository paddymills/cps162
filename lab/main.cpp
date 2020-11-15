#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// function prototypes
int getNumbers(vector<int> &);
void heapify(vector<int> &);
void sort(vector<int> &);

const string FILE_NAME = "heaplist.txt";

int main()
{
  vector<int> numbers;

  // read input file
  if (!getNumbers(numbers))
    return 1;

  vector<int>::iterator it = numbers.begin();
  while (it != numbers.end())
  {
    cout << *it << endl;
    it++;
  }

  return 0;
}

int getNumbers(vector<int> &nums)
{
  string num;

  // create file input stream
  ifstream inputFile(FILE_NAME, ios::in);

  // test for successful file open
  if (inputFile.fail())
  {
    cout << "Failed to open " << FILE_NAME << endl;
    return 0;
  }

  // read file contents
  while (!inputFile.eof())
  {
    // read number
    getline(inputFile, num);
    if (num == "")
      break;

    nums.push_back(stoi(num));
  }

  // close input file
  inputFile.close();

  return 1;
}