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

int reversePolish(Stack stack, string expression)
{
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            stack.push(expression[i] - '0');
            continue;
        }
        int y = stack.pop(), x = stack.pop();
        if (expression[i] == '+')
            stack.push(x + y);
        else if (expression[i] == '-')
            stack.push(x - y);
        else if (expression[i] == '*')
            stack.push(x * y);
        else if (expression[i] == '/')
            stack.push(x / y);
    }
    return stack.peek();
}

int main(void)
{
    Stack myStack;
    string myExpression = "512+4*+3-";
    int result = reversePolish(myStack, myExpression);
    cout << result << endl;
    return 0;
}