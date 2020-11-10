#include <iostream>
#include <fstream>

using namespace std;

int INVENTORY_SIZE = 24;
string FILE_NAME = "candy.txt";

struct Candy
{
  string IDcode;   // 4-char alphanumeric code
  string itemName; // name/description of the candy
  double quantity; // quantity on hand, in pounds
  double price;    // price per pound
};

// function prototypes
bool getCandy(Candy *);
int hashItemId(string);

int main()
{
  Candy inventory[24];

  // fill inventory
  // get_candy returns false if file cannot open
  if (!getCandy(inventory))
    return 0;

  return 0;
}

bool getCandy(Candy *arr)
{
  int index;

  fstream inputFile(FILE_NAME, ios::in);

  // test for successful file open
  if (inputFile.fail())
  {
    cout << "Failed to open " << FILE_NAME << endl;
    return false;
  }

  // read file contents
  while (!inputFile.eof())
  {
    Candy temp;

    // read values
    inputFile >> temp.IDcode;
    inputFile >> temp.itemName;
    inputFile >> temp.quantity;
    inputFile >> temp.price;

    cout << temp.itemName << endl;

    // calculate hash
    index = hashItemId(temp.IDcode);

    // store in inventory
    arr[index] = temp;
  }

  // close input file
  inputFile.close();

  return true;
}

int hashItemId(string id)
{
  return 0;
}
