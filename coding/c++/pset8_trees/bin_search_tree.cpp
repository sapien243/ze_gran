#include <iostream>

using namespace std;

class Node
{
private:
    int value;
    Node *right, *left;
    Node *mini(Node **root);

public:
    Node(int data);
    void insert(int fruit);
    bool remove(int fruit, Node **root);
    void inOrder();
    void preOrder();
    void postOrder();
    int search(int fruit);
    void clear();
};
Node::Node(int data)
{
    value = data;
    right = NULL, left = NULL;
}
void Node::insert(int fruit)
{
    // Handles left case, fruit is less than / equal to value
    if (this->value >= fruit)
    {
        if (!this->left)
            this->left = new Node(fruit);
        else
            this->left->insert(fruit);
    }
    // Handles right case, fruit is greater than value
    else if (!this->right)
        this->right = new Node(fruit);
    else
        this->right->insert(fruit);
}
bool Node::remove(int fruit, Node **root)
{
    Node *temp = *root;
    // Look for value
    if (temp->value > fruit)
        return (!temp->left) ? false : temp->left->remove(fruit, &temp->left);

    else if (temp->value < fruit)
        return (!temp->right) ? false : temp->right->remove(fruit, &temp->right);

    // Deletion
    if (!temp->right && !temp->left)
        *root = NULL;

    else if (!temp->right)
        *root = temp->left;

    else if (!temp->left)
        *root = temp->right;

    else
    {
        *root = mini(&temp->right);
        (*root)->right = temp->right, (*root)->left = temp->left;
    }
    delete temp;
    return true;
}
Node *Node::mini(Node **root)
{
    Node *temp = *root;
    if (!temp->left)
    {
        *root = (!temp->right) ? NULL : temp->right;
        return temp;
    }
    return mini(&temp->left);
}
void Node::inOrder()
{
    if (this->left)
        this->left->inOrder();
    cout << this->value << " ";
    if (this->right)
        this->right->inOrder();
}
void Node::preOrder()
{
    cout << this->value << " ";
    if (this->left)
        this->left->preOrder();
    if (this->right)
        this->right->preOrder();
}
void Node::postOrder()
{
    if (this->left)
        this->left->postOrder();
    if (this->right)
        this->right->postOrder();
    cout << this->value << " ";
}
int Node::search(int fruit)
{
    int temp = 0;
    // Return -1 if absent, depth if present
    if (this->value == fruit)
        return 0;
    else if (this->value > fruit)
        temp = (!this->left) ? -1 : this->left->search(fruit);
    else
        temp = (!this->right) ? -1 : this->right->search(fruit);
    return (temp == -1) ? -1 : temp + 1;
}
void Node::clear()
{
    if (this->left)
        this->left->clear();
    if (this->right)
        this->right->clear();
    delete this;
}

int main(void)
{
    Node *myTree = new Node(4); // NB: we begin with myTree having one element

    // insert some elements
    myTree->insert(2);
    myTree->insert(6);
    myTree->insert(1);
    myTree->insert(3);
    myTree->insert(5);
    myTree->insert(7);
    myTree->insert(8);

    // check traversal
    myTree->inOrder(); // output should be: 1 2 3 4 5 6 7
    cout << endl;
    myTree->preOrder(); // output should be: 4 2 1 3 6 5 7
    cout << endl;
    myTree->postOrder(); // output should be: 1 3 2 5 7 6 4
    cout << endl;

    // chech search
    cout << "Number of hops: " << myTree->search(4) << endl;  // should be 0 since 4 is the root node
    cout << "Number of hops: " << myTree->search(2) << endl;  // should be 1 since it takes just 1 hop to get to 2
    cout << "Number of hops: " << myTree->search(7) << endl;  // should be 2 since it takes 2 hops to get to 7
    cout << "Number of hops: " << myTree->search(8) << endl;  // should be 3 since it takes 3 hop to get to 8
    cout << "Number of hops: " << myTree->search(10) << endl; // should be -1 since 10 is not in the tree

    // check remove
    cout << myTree->remove(0, &myTree) << endl; // true = 1, false = 0
    if (myTree != NULL)
        myTree->inOrder();
    cout << endl;

    if (myTree != NULL)
        myTree->clear();
    return 0;
}
