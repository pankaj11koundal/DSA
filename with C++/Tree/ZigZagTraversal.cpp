#include<iostream>
#include<stack>

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

void zigZagTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    
    bool leftToRight = true;
    stack<Node *> curr, next;
    curr.push(root);

    while (!curr.empty())
    {
        Node *temp = curr.top();
        curr.pop();

        if (temp)
        {
            cout << temp->getData() << " ";
            if (leftToRight)
            {
                if (temp->left)
                {
                    next.push(temp->left);
                }
                if (temp->right)
                {
                    next.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    next.push(temp->right);
                }
                if (temp->left)
                {
                    next.push(temp->left);
                }
            }
        }
        
        if (curr.empty())
        {
            swap(curr, next);
            leftToRight = !leftToRight;
        }
    }
}

int main()
{
    Node *root = CreateNode();
    zigZagTraversal(root);
    return 0;
}