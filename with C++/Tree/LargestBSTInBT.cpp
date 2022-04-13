#include <iostream>
#include <bits/stdc++.h>

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

Info largestBSTInBT(Node *root)
{
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, true, 0};
    }

    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->getData(), root->getData(), true, 1};
    }

    Info left = largestBSTInBT(root->left);
    Info right = largestBSTInBT(root->right);
    
    Info curr;
    curr.size = (left.size + right.size + 1);

    if (left.isBst && right.isBst && root->getData() > left.max && root->getData() < right.min)
    {
        curr.min = min(left.min, min(right.min, root->getData()));
        curr.max = max(right.max, max(left.max, root->getData()));
        curr.ans = curr.size;
        curr.isBst = true;
        return curr;
    }

    curr.isBst = false;
    curr.ans = max(left.ans, right.ans);

    return curr;
}

int main()
{
    Node *root = CreateNode();
    Info largest = largestBSTInBT(root);
    cout << largest.ans;
    return 0;
}

