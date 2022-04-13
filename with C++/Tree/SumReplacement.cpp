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

void levelTraversal(Node *root)
{
    Node *node;
    if (root == NULL)
    {
        cout << "Unable to traverse";
    }
    
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->getData() << " ";
            // cout << node->left << " " << node->right;
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            // cout << "inside else if";
            q.push(NULL);
        }

        // node->getData();
    }
    // cout << "End of levelTraversal";
}

void sumReplacement(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    
    sumReplacement(root->left);
    sumReplacement(root->right);

    if (root->left)
    {
        root->setData(root->left->getData());
    }
    if (root->right)
    {
        root->setData(root->right->getData());
    }
}

int main()
{
    Node *root = CreateNode();
    levelTraversal(root);
    cout << endl;
    sumReplacement(root);
    levelTraversal(root);
    return 0;
}