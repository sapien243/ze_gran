#include <iostream>

using namespace std;

class Stack
{
private:
    int mem[10];
    int siz;

public:
    Stack();
    int size();
    bool isEmpty();
    bool push(int newElement);
    int pop();
    int peek();
    void printStack();
};

Stack::Stack()
{
    siz = 0;
}
int Stack::size()
{
    return siz;
}
bool Stack::isEmpty()
{
    if (siz == 0)
        return true;
    return false;
}
bool Stack::push(int newElement)
{
    if (siz == 5 || newElement == -1)
        return false;
    mem[siz] = newElement, siz++;
    return true;
}
int Stack::pop()
{
    if (siz == 0)
        return -1;
    siz--;
    return mem[siz];
}
int Stack::peek()
{
    if (siz == 0)
        return -1;
    return mem[siz - 1];
}
void Stack::printStack()
{
    if (siz == 0)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < siz; i++)
        cout << mem[i] << " ";
    cout << endl;
}

int main(void)
{
    Stack vanillaStack;

    // Print out the current size of vanillaStack
    cout << vanillaStack.size() << endl; // size should be 0

    if (vanillaStack.push(5))
        vanillaStack.printStack(); // output should be: 5
    if (vanillaStack.push(3))
        vanillaStack.printStack(); // output should be: 5 3
    if (vanillaStack.push(8))
        vanillaStack.printStack(); // output should be: 5 3 8
    if (vanillaStack.push(6))
        vanillaStack.printStack(); // output should be: 5 3 8 6
    if (vanillaStack.push(7))
        vanillaStack.printStack(); // output should be: 5 3 8 6 7
    if (vanillaStack.push(10))
        vanillaStack.printStack(); // no output due to stack overflow

    // Print out the current size of vanillaStack
    cout << vanillaStack.size() << endl; // size should be 5
    cout << vanillaStack.peek() << endl; // element at the top should be 7

    vanillaStack.pop();
    vanillaStack.printStack(); // output should be: 5 3 8 6
    vanillaStack.pop();
    vanillaStack.printStack(); // output should be: 5 3 8
    vanillaStack.pop();
    vanillaStack.printStack(); // output should be: 5 3
    vanillaStack.pop();
    vanillaStack.printStack(); // output should be: 5
    vanillaStack.pop();
    vanillaStack.printStack(); // output should be: -1

    // Try to pop from an empty stack
    cout << vanillaStack.pop() << endl;
    return 0;
}