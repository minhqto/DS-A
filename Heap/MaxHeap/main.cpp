#include "BinaryMaxHeap.h"
#include <iostream>

int main()
{

    BinaryMaxHeap<int> myBMH;
    std::cout << (myBMH.isEmpty() ? "True" : "False") << std::endl;
    myBMH.insert(2);
    myBMH.insert(3);
    myBMH.insert(5);
    myBMH.insert(8);
    myBMH.insert(10);
    myBMH.insert(13);

        // std::cout << myBMH.getMax() << std::endl;
    myBMH.displayHeap();
    return 0;
}