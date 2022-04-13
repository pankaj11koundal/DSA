// Program to implement flatten the binary tree in such a manner that the inoder order traversal of flatten binary tree should give the preorder traversal of the original tree
#include <iostream>

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

void flattenBinaryTree(Node *root)
{
    if ( root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->left != NULL)
    {
        flattenBinaryTree(root->left);
        Node *t = root->right;
        root->right = root->left;
        root->left = NULL;
        Node *temp = root->right;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }

        temp->right = t;
    }

    // cout << "Left portion completed: " << endl;
    flattenBinaryTree(root->right);
    // cout << "returning back: ";
}

int main()
{
    Node *root = CreateNode();
    flattenBinaryTree(root);
    cout << "Inside main function: ";
    Inorder(root);
    return 0;
}
