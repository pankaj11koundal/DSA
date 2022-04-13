// Progaram to find the path with maximum sum in a tree

#include<bits/stdc++.h>
#include<iostream>

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

int calcSum(Node *root, int &k)
{
    if (root == NULL)
    {
        return 0;   
    }
    
    int left = calcSum(root->left, k);
    int right = calcSum(root->right, k);

    int nodeMax = max(max(root->getData(), root->getData() + left + right), max(root->getData() + left, root->getData() + right));

    k = max(k, nodeMax);

    int singleMaxPath = max(max(left + root->getData(), right + root->getData()), root->getData());
    return singleMaxPath;
}


int maxSumPath(Node *root)
{
    int ans = INT_MIN;
    calcSum(root, ans);
    return ans;
}

int main()
{
    Node *root = CreateNode();
    cout << maxSumPath(root);
    return 0;
}
