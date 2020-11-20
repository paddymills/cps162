#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// function prototypes
int getNumbers(vector<int> &);
void heapify(vector<int> &);
void heapsort(vector<int> &);
void percolateUp(vector<int> &, int);
void percolateDown(vector<int> &, int);
void swapItems(vector<int> &, int, int);
void displayHeap(vector<int> &);

const string FILE_NAME = "heaplist.txt";

int main()
{
  vector<int> numbers;

  // read input file
  if (!getNumbers(numbers))
    return 1;

  cout << "\nInitial heap from file:" << endl;
  displayHeap(numbers);

  heapify(numbers);
  cout << "\nAfter heapify()" << endl;
  displayHeap(numbers);

  heapsort(numbers);
  cout << "\nList after heapsort()" << endl;
  for (int i = 0; i < numbers.size(); i++)
  {
    cout << numbers[i] << " ";
  }
  cout << endl;
  

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

void heapify(vector<int> &nums)
{
  // start at bottom of heap
  // apply percolate-down to trees (not leaf nodes)
  for (int root = nums.size() - 1; root >= 0; root--)
    percolateUp(nums, root);
}

void heapsort(vector<int> &nums)
{
  for (int len = nums.size() - 1; len > 0; len--)
  {
    // swap first and last element
    // last element is actually the last element in the unsorted list
    // each iteration shrinks the list by 1, since the last
    // element is known to be in order
    swapItems(nums, 0, len);

    percolateDown(nums, len);
  }
}

void percolateUp(vector<int> &nums, int root)
{
  int left, right; // node indexes
  int greaterTree;  // for assigning tree that changed (do not have to duplicate code)
  
  // assign child node indexes
  left = 2 * root;
  if (left == 0)
    left = 1;
  right = left + 1;

  // return if node has no children
  if (left >= nums.size())
    return;

  // switch nodes if root is not the largest number
  if (nums[root] < nums[left] || nums[root] < nums[right])
  {
    if (nums[left] >= nums[right])
      // left is larger (or same) than right
      greaterTree = left;
    else
      // right is larger number
      greaterTree = right;

    // swap root and tree that is greater
    swapItems(nums, root, greaterTree);

    // percolate-down tree that changed
    percolateUp(nums, greaterTree);
  }
}

void percolateDown(vector<int> &nums, int stop)
{
  int left, right, root;

  root = 0;
  left = 1;
  right = 2;

  while (nums[root] < nums[left] || nums[root] < nums[right])
  {
    if (right < stop && nums[right] > nums[left])
    {
      // right is larger than left
      swapItems(nums, root, right);
      root = right;
    }
    else if (left < stop)
    {
      // left is larger number
      swapItems(nums, root, left);
      root = left;
    }
    else  // both left and right are in sorted territory
      break;
    
    left = root * 2;
    right = left + 1;
  }
}

void swapItems(vector<int> &nums, int root, int other)
{
  int temp; // for swapping elements

  temp = nums[root];
  nums[root] = nums[other];
  nums[other] = temp;
}

void displayHeap(vector<int> &nums)
{
  int width, padding;
  int level, levels, levelCapacity;
  int items;
  int drawing = 1;
  
  // calculate number of levels
  levels = 0;
  items = 0;
  levelCapacity = 1;
  while (items < nums.size())
  {
    items += levelCapacity;

    // increment
    levelCapacity *= 2;
    levels++;
  }

  // set max width of line
  width = (levelCapacity) * 5;

  // print separator
  for (int i = 0; i < width; i++)
    cout << "=";
  cout << endl;

  items = 0;
  levelCapacity = 1;
  level = 1;
  while (items < nums.size())
  {
    // calculate padding
    //     width 
    // ------------------ - [half of item setw(4)]
    //  2 * [items in row]
    padding = (width / ( 2 * levelCapacity )) - 2;

    // draw tree lines
    cout << setw(padding + 3);
    for (int i = 0; i < levelCapacity && items < nums.size(); i++)
    {
      if (level == 1)
        break;

      cout << "+";
      for (int i = 0; i < (2 * padding + 3); i++)
      {
        if (drawing > 0)
          cout << "-";
        else
          cout << " ";
      }

      drawing *= -1;
      items++;
    }
    cout << endl;

    // output level values
    for (int i = 0; i < levelCapacity && items < nums.size(); i++)
    {
      // print [padding][num][padding]
      cout << setw(padding) << " ";
      cout << setw(4) << nums[items];
      cout << setw(padding) << " ";

      items++;
    }
    cout << endl;
    
    // increment level and capacity
    levelCapacity *= 2;
    level++;
  }

  // print separator
  for (int i = 0; i < width; i++)
    cout << "=";
  cout << endl;


}