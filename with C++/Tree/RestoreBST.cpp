#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Node
{
private:
    int data;

public:
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }

    int getData()
    {
        return data;
    }

    void setData(int val)
    {
        data = val;
    }
};

class Info
{
public:
    int size;
    int max;
    int min;
    bool isBst;
    int ans;
};

Node *CreateNode()
{
    int data;
    cout << "Enter the data you want to enter in the root: ";
    cin >> data;
    char lchoice, rchoice;
    Node *root = new Node(data);

    cout << "to create left root of " << root->getData() << " press y: ";
    cin >> lchoice;
    if (lchoice == 'Y' || lchoice == 'y')
    {
        cout << "Creating the left root of " << root->getData() << "\n";
        root->left = CreateNode();
    }
    else
    {
        root->left = NULL;
    }

    cout << "to create right root of " << root->getData() << " press y: ";
    cin >> rchoice;
    if (rchoice == 'y' || rchoice == 'Y')
    {
        cout << "Creating the right root of " << root->getData() << "\n";
        root->right = CreateNode();
    }
    else
    {
        root->right = NULL;
    }

    return root;
}

void calcPointer(Node *root, Node **first, Node **last, Node **mid, Node **prev)
{
    if (root == NULL)
    {
        return;
    }

    calcPointer(root->left, first, last, mid, prev);

    if (*prev && (*prev)->getData() > root->getData())
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;

    calcPointer(root->right, first, last, mid, prev);
}

void swap(Node *a, Node *b)
{
    int temp = a->getData();
    a->setData(b->getData());
    b->setData(temp);
}
void restoreBST(Node *root)
{
    Node *first = NULL, *last = NULL, *mid = NULL, *prev = NULL;
    calcPointer(root, &first, &last, &mid, &prev);

    if (first && last)
    {
        swap(first, last);
    }
    else if (first && mid)
    {
        swap(first, mid);
    }
}

void Inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left);
    cout << root->getData() << " ";
    Inorder(root->right);
}

int main()
{
    Node *root = CreateNode();
    Inorder(root);
    cout << endl;
    restoreBST(root);
    Inorder(root);
    return 0;
}

//     4
//    / \
//   2   6
//  / \  / \
// 7   3 5  1