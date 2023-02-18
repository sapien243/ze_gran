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

int balancedBrackets(Stack stack, string brackets)
{
    int i = 0, k = 0;
    for (; brackets[i] != '\0'; i++)
    {
        if (brackets[i] == '[' || brackets[i] == '{' ||
            brackets[i] == '(' || brackets[i] == '<')
            stack.push(brackets[i]);
        else if (brackets[i] - 2 == stack.peek() ||
                 brackets[i] - 1 == stack.peek())
            stack.pop(), k = 0;
        else if (brackets[i] == ']' || brackets[i] == '}' ||
                 brackets[i] == ')' || brackets[i] == '>')
            return i;
        else
            k++;
    }
    if (stack.size() == 0)
        return -1;
    else
        return i - k;
}

int main(void)
{
    Stack myStack;
    string brackets = "ii{[(i>)}";
    cout << balancedBrackets(myStack, brackets) << endl;
    return 0;
}