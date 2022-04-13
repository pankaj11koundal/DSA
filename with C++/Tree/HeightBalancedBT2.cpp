// Cpp Program to check whether a BT is a height balanced tree or not with time complexity: O(n)

#include<bits/stdc++.h>

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

Node *CreateNode()
{
    int data;
    cout << "Enter the data you want to enter in the node: ";
    cin >> data;
    char lchoice, rchoice;
    Node *root = new Node(data);

    cout << "to create left node of " << root->getData() << " press y: ";
    cin >> lchoice;
    if (lchoice == 'Y' || lchoice == 'y')
    {
        cout << "Creating the left node of " << root->getData() << "\n";
        root->left = CreateNode();
    }
    else
    {
        root->left = NULL;
    }

    cout << "to create right node of " << root->getData() << " press y: ";
    cin >> rchoice;
    if (rchoice == 'y' || rchoice == 'Y')
    {
        cout << "Creating the right node of " << root->getData() << "\n";
        root->right = CreateNode();
    }
    else
    {
        root->right = NULL;
    }

    return root;
}

int calcHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    
    return max(calcHeight(root->left),calcHeight(root->right)) + 1;
}

bool heightBalance(Node *root, int *height)
{
    if(root == NULL)
    {
        *height = 0;
        return true;
    }

    int lheight = 0, rheight = 0;

    if(!heightBalance(root->left, &lheight))
    {
        return false;
    }
    if(!heightBalance(root->right, &rheight))
    {
        return false;
    }
    *height = max(lheight, rheight) + 1;

    if (abs(lheight - rheight) < 1)
    {
        return true;
    }
    return false;
}

int main()
{
    Node *root = CreateNode();
    int  height = 0;
    cout << heightBalance(root, &height);
    return 0;
}