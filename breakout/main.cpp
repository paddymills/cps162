#include <iostream>

using namespace std;

template <typename ElementType>
void recLinearSearch(ElementType x[], ElementType item, int n, int start, bool &found, int &loc)
{
    /*--------------------------------------------------------------
    Recursively linear search a list stored in an array x for an item.
    Precondition: n is the number of items in the array and
    0 <= start <= n. Initial call is with start = 0.
    Postcondition: found is true and loc is the position of item if 
    the search is successful; otherwise found is false and loc == n.
    --------------------------------------------------------------*/

    if (x[start] == item)
    {
        found = true;
        loc = start;
    }
    else if (start < n)
        recLinearSearch(x, item, n, ++start, found, loc);
}

// template <typename ElementType>
// void recLinkedLinearSearch(NodePointer first, ElementType item, bool &found, NodePointer &locptr)
// {
//     /*-------------------------------------------------------------
//     Recursively linear search a linked list for an item.
//     Precondition: first points to first node in the linked list.
//     Postcondition: found is true and locptr positioned at item if the
//     search is successful; otherwise found is false and loc == n.
//     --------------------------------------------------------------*/

//     if (*first->value == item)
//     {
//         found = true;
//         locptr = first;
//     }

//     else if (*first->next)
//         recLinkedLinearSearch(*first->next, item, found, locptr);
// }

void test1(int num)
{
    const int SIZE = 7;
    int a[SIZE] = {1, 2, 3, 4, 5, 6, 7};
    bool f = false;
    int lc = -1;

    recLinearSearch(a, num, SIZE, 0, f, lc);

    cout << "test(" << num << "): ";
    if (f)
        cout << "found at " << lc;
    else
        cout << "not found";

    cout << endl;
}

int main()
{
    test1(4);
    test1(2);
    test1(8);

    return 0;
}