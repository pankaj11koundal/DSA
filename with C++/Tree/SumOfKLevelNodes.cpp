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

int sumOfKLevel(Node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int level = 0, sum = 0;
    queue<Node *> q;
    Node *node;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node = q.front();
        q.pop();

        if (node != NULL)
        {
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
            if (level == k)
            {
                sum += node->getData();
            }
        }
        else if (!q.empty())
        {
            level++;
            q.push(NULL);
        }
    }
    return sum;
}

int main()
{
    Node *root = CreateNode();
    cout << sumOfKLevel(root, 2);
    return 0;
}