/*
  Patrick Miller
  Nyhoff Chapter 12 Lab
  11/10/20
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int INVENTORY_SIZE = 24;
const string FILE_NAME = "candy.txt";

struct Candy
{
  string IDcode;   // 4-char alphanumeric code
  string itemName; // name/description of the candy
  double quantity; // quantity on hand, in pounds
  double price;    // price per pound
};

// function prototypes
int getCandy(Candy *);
int getIndex(Candy *, string);
int menu(Candy *);
void availabilityCheck(Candy *);
void purchase(Candy *);
void delivery(Candy *);
void inventory(Candy *);

int main()
{
  Candy inventory[INVENTORY_SIZE];
  int loopOption;

  // fill inventory
  // get_candy returns false if file cannot open
  if (!getCandy(inventory))
    return 0;

  // loop for menu
  while (menu(inventory))
    ;

  return 0;
}

bool getCandy(Candy *arr)
{
  // struct values
  string id, name, qty, price;

  // hash table index
  int index;

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
    // read id
    getline(inputFile, id);
    if (id == "")
      break;

    // read next 3 values as needed
    getline(inputFile, name);
    getline(inputFile, qty);
    getline(inputFile, price);

    // calculate hash index
    index = getIndex(arr, id);

    // pop last 2 characters from string entries (\r char)
    id.pop_back();
    name.pop_back();

    // store in inventory
    arr[index].IDcode = id;
    arr[index].itemName = name;
    arr[index].quantity = stod(qty);
    arr[index].price = stod(price);
  }

  // close input file
  inputFile.close();

  return 1;
}

int getIndex(Candy *arr, string id)
{
  int index;

  // primary hash
  index = stoi(id.substr(1, 3)) % INVENTORY_SIZE;

  // find unused index by probing
  // probing function uses the numbers in the ID,
  // adding them to the hash index
  // !NOT PERFECT, COLLISONS COULD HAPPEN!
  for (int i = 1; i <= 3; i++)
  {
    index += stoi(id.substr(i, 1));

    // wrap around if passed array bounds
    if (index >= INVENTORY_SIZE)
      index -= INVENTORY_SIZE;

    // index found if empty slot or
    // id in slot matches id (needed to retrieve item later)
    if (arr[index].IDcode == "" || arr[index].IDcode == id)
      break;
  }

  return index;
}

int menu(Candy *arr)
{
  string option;

  // print menu
  cout << "Main Menu:" << endl;
  cout << "  1) Availability Check" << endl;
  cout << "  2) Item Purchase" << endl;
  cout << "  3) Item Delivery" << endl;
  cout << "  4) Print Inventory" << endl;
  cout << "  5) Quit" << endl;
  cout << "> ";

  // get option from user
  cin >> option;

  switch (option[0])
  {
  case '1':
    availabilityCheck(arr);
    break;
  case '2':
    purchase(arr);
    break;
  case '3':
    delivery(arr);
    break;
  case '4':
    inventory(arr);
    break;
  case '5': // Quit
    return 0;
  default:
    cout << "Invalid option!" << endl;
  }

  return 1;
}

void availabilityCheck(Candy *arr)
{
  string id;
  int index;

  // get id from user
  cout << "Item ID: ";
  cin >> id;

  // calculate index
  index = getIndex(arr, id);

  // in stock
  // must be a valid ID and quantity above 0
  if (arr[index].IDcode != "" && arr[index].quantity > 0)
    cout << id << " in stock and the price is $" << arr[index].price << endl;

  // out of stock
  else
    cout << id << " is not in stock" << endl;
}

void purchase(Candy *arr)
{
  string id;
  int index, qty;

  // get id from user
  cout << "Item ID: ";
  cin >> id;

  // calculate index
  index = getIndex(arr, id);

  // validate index entered is OK
  // must be a valid ID and quantity above 0
  if (arr[index].IDcode == "" && arr[index].quantity < 0)
  {
    cout << "Invalid ID" << endl;
    return;
  }

  // get qty from user
  cout << "Quantity to purchase: ";
  cin >> qty;

  arr[index].quantity -= qty;
}

void delivery(Candy *arr)
{
  string id;
  int index, qty;

  // get id from user
  cout << "Item ID: ";
  cin >> id;

  // calculate index
  index = getIndex(arr, id);

  // validate index entered is OK
  // must be a valid ID
  if (arr[index].IDcode == "")
  {
    cout << "Invalid ID" << endl;
    return;
  }

  // get qty from user
  cout << "Quantity to deliver: ";
  cin >> qty;

  arr[index].quantity += qty;
}

void inventory(Candy *arr)
{
  cout << setprecision(2) << fixed;

  // print header
  cout << setw(5) << "ID";
  cout << setw(20) << "Item";
  cout << setw(7) << "Qty";
  cout << " Price" << endl;

  cout << "=======================================" << endl;

  for (int i = 0; i < INVENTORY_SIZE; i++)
  {
    if (arr[i].IDcode != "" && arr[i].quantity > 0)
    {
      cout << setw(5) << arr[i].IDcode;
      cout << setw(20) << arr[i].itemName;
      cout << setw(7) << arr[i].quantity << " ";
      cout << "$" << arr[i].price << endl;
    }
  }

  cout << "=======================================" << endl;
}