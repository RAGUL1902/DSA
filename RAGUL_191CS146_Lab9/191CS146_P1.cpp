//Kindly use g++ to compile the program as this is written in c++

#include <bits/stdc++.h>
using namespace std;

//Node for the bst
struct Node
{
    char key;
    struct Node *left, *right;
};

//function to create new node
Node *newNode(int data)
{
    Node *temp = new Node;

    temp->key = data;

    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


//function to insert new node
Node *BSTInsert(Node *root, char key)
{
    Node *newnode = newNode(key);
    Node *x = root;
    Node *y = NULL;
    while (x != NULL)
    {
        y = x;
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    if (y == NULL)
        y = newnode;
    else if (key < y->key)
        y->left = newnode;
    else
        y->right = newnode;
    return y;
}


//function to print inorder traversal of the bst
void BSTInorderStack(struct Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->key << " ";
        curr = curr->right;
    }
}

//sub function to find location of parent
void findParent(struct Node *node,
                char val, struct Node *parent)
{
    if (node == NULL)
        return;
    if (node->key == val)
    {
        if (parent == 0)
        {
            cout << "\nLocation of the parent: -1(The entered element is root) ";
            return;
        }
        cout << "\nLocation of the parent: " << parent;
        return;
    }
    else
    {
        findParent(node->left, val, node);
        findParent(node->right, val, node);
    }
}


//function to search the given node
struct Node *BSTSearch(struct Node *root, char key)
{
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return BSTSearch(root->right, key);
    return BSTSearch(root->left, key);
}

int main()
{

    Node *root = NULL;
    cout << "\nIinitally the tree is empty.\nEnter a char element for root: ";
    char rootElement;
    cin >> rootElement;
    root = BSTInsert(root, rootElement);

    cout << "\nEnter 1 to insert a char element: ";
    cout << "\nEnter 2 to search an element";
    cout << "\nEnter 3 to show inorder traversal";
    cout << "\nEnter 4 to quit";

    while (1)
    {
        cout << "\n-->";
        int option;
        cin >> option;
        if (option == 1)
        {
            cout << "Enter the char to insert: ";
            char element;
            cin >> element;
            if (BSTSearch(root, element) == 0)
                BSTInsert(root, element);
            else
            {
                cout << "\nElement already present in tree";
            }
        }
        else if (option == 2)
        {
            cout << "\nEnter the char to search: ";
            char a;
            cin >> a;
            if (BSTSearch(root, a) == 0)
            {
                cout << "\nEnlemenet not present";
            }
            else
            {
                cout << "\nlocation of the element: " << BSTSearch(root, a);
                findParent(root, a, 0);
            }
        }
        else if (option == 3)
        {
            BSTInorderStack(root);
        }
        else if (option == 4)
        {
            return 0;
        }
        else
        {
            cout << "\nEnter a valid option ";
        }
    }
    return 0;
}