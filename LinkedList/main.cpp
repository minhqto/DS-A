#include "LinkedList.h"
int main()
{
    List myList;
    int range = 10;
    myList.insert(1);
    myList.insert(2);
    myList.insert(3);
    myList.remove(3);
    myList.remove(2);
    myList.remove(1);
    myList.display();
    for (int i = 0; i < range; i++)
    {
        myList.insert(i);
    }
    myList.remove(100);
    for (int i = 0; i < range / 2; i++)
    {
        myList.remove(i * 2);
    }
    myList.display();
    return 0;
}