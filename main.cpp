#include "LinkedList.h"
#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

int main()
{
     LinkedList list;

     const int APPEND_COUNT = 4;
     const int INSERT_COUNT = 5;
     const int DELETE_COUNT = 6;

     int appendNumbers[APPEND_COUNT] = {2, 5, 8, 15};
     int insertNumbers[INSERT_COUNT] = {3, 4, 7, 1, 9};
     int insertIndexes[INSERT_COUNT] = {1, -3, 3, 0, 15};
     int deleteIndexes[DELETE_COUNT] = {2, 4, 20, 0, 4, -6};

     cout << right; // numbers: right justification

     // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     // ~           append items           ~
     // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     cout << "Appending nodes:" << endl;
     for (int i = 0; i < APPEND_COUNT; i++)
     {
          cout << "\tAppending ";
          cout << setw(2);
          cout << appendNumbers[i];
          cout << ": ";

          list.displayNodes();
          cout << " -> ";
          list.appendNode(appendNumbers[i]);
          list.displayNodes();
          cout << endl;
     }

     // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     // ~           insert items           ~
     // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     cout << "Inserting nodes:" << endl;
     for (int i = 0; i < INSERT_COUNT; i++)
     {
          cout << "\tInserting ";
          cout << setw(2);
          cout << insertNumbers[i];
          cout << " at index ";
          cout << setw(2) << insertIndexes[i];
          cout << ": ";

          list.displayNodes();
          cout << " -> ";
          list.insertNode(insertNumbers[i], insertIndexes[i]);
          list.displayNodes();
          cout << endl;
     }

     // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     // ~           delete items           ~
     // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
     cout << "Deleting nodes:" << endl;
     for (int i = 0; i < DELETE_COUNT; i++)
     {
          cout << "\tDeleting index ";
          cout << setw(2) << deleteIndexes[i];
          cout << ": ";

          list.displayNodes();
          cout << " -> ";
          list.deleteNode(deleteIndexes[i]);
          list.displayNodes();
          cout << endl;
     }
}
