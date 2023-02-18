#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val);
    void printList();
    void insertTail(int newElement);
    Node *insertHead(int newElement);
    void insertMiddle(int newElement, int position);
};
Node::Node(int val)
{
    data = val, next = NULL;
}
void Node::printList()
{
    for (Node *temp = this; temp != NULL; temp = temp->next)
    {
        cout << temp->data << " ";
    }
    cout << endl;
}
void Node::insertTail(int newElement)
{
    for (Node *temp = this; true; temp = temp->next)
    {
        if (temp->next == NULL)
        {
            temp->next = new Node(newElement);
            return;
        }
    }
}
Node *Node::insertHead(int newElement)
{
    Node *fist = new Node(newElement);
    fist->next = this;
    return fist;
}
void Node::insertMiddle(int newElement, int position)
{
    Node *temp = this, *newe = NULL;
    if (position == 0)
    {
        newe = new Node(data), newe->next = next;
        data = newElement, next = newe;
        return;
    }
    newe = new Node(newElement);
    for (int i = 1; i < position && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    newe->next = temp->next, temp->next = newe;
}

int main(void)
{
    Node *myList;
    int size = 5;
    int myArray[] = {20, 30, 40, 50};

    myList = new Node(10);
    for (int i = 0; i < size - 1; i++)
    {
        myList->insertTail(myArray[i]);
    }
    myList->printList();
    myList->insertMiddle(25, 0);
    // Print the state of the linked list
    myList->printList();

    delete myList;
    return 0;
}