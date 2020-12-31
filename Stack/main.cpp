#include "Stack.h"
#include "string.h"
#include <vector>

// Driver code
int main()
{

    Stack<int> myStack;
    Stack<std::string> stringStack;

    // Testing ints

    for (int i = 0; i < 10; i++)
    {
        myStack.push(i);
    }

    for (int i = 0; i < 5; i++)
    {
        myStack.pop();
    }

    std::cout << myStack.peek() << std::endl;
    myStack.printStack();

    std::cout << myStack.isEmpty() << std::endl;

    for (int i = 0; i < 5; i++)
    {
        myStack.pop();
    }

    std::cout << myStack.isEmpty() << std::endl;
    myStack.printStack();

    // Testing strings

    std::vector<std::string> myStrings = {"hello", "world", "c++"};
    for (std::string s : myStrings)
    {
        stringStack.push(s);
    }
    std::cout << stringStack.peek() << std::endl;
    stringStack.printStack();
    stringStack.pop();
    stringStack.printStack();

    return 0;
}