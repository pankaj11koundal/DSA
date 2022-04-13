// cpp program to get the diameter of tree within O(n) complexity

#include<bits/stdc++.h>

using namespace std;

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

    void setData(int val)
    {
        data += val;
    }
};

int calcdiameter(Node *root, int *height)
{
    if (root == NULL)
    {
        height = 0;
        return 0;
    }

    int lh = 0;
    int rh = 0;
    int ldiameter = calcdiameter(root->left, &rh);
    int rdiameter = calcdiameter(root->right, &lh);
    int currdiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currdiameter, max(ldiameter, rdiameter));
}

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

int main()
{
    int height = 0;
    Node *root = CreateNode();
    cout << calcdiameter(root, &height);
    return 0;
}