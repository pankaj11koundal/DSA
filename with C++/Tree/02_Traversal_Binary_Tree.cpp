// C++ implementation to show the implementation of the binary tree traversal

// implementation of insertion of node in the tree 

#include<iostream>

using namespace::std;

int count = 0;
int i = 1;
class Node
{
private:
    int data;

public:
    Node *left;
    Node *right;

    Node()
    {
        left = NULL;
        right = NULL;
    }

    void EnterData()
    {
        cout << "Enter the data in the tree: ";
        cin >> data;
        count++;
    }

    int ReturnData()
    {
        return data;
    }
};

Node *CreateNode()
{
    char lchoice, rchoice; 
    Node *root = new Node();
    root->EnterData();

    cout << "to create left node of " << root->ReturnData() << " press y: ";
    cin >> lchoice;
    if (lchoice == 'Y' || lchoice == 'y')
    {
        cout << "Creating the left node of " << root->ReturnData() << "\n";
        root->left =  CreateNode();
    }
    else
    {
        root->left = NULL;
    }
    

    cout << "to create right node of " << root->ReturnData() << " press y: ";
    cin >> rchoice;
    if (rchoice == 'y' || rchoice == 'Y')
    {
        cout << "Creating the right node of " << root->ReturnData() << "\n";
        root->right = CreateNode();
    }
    else
    {
        root->right = NULL;
    }
    
    cout << "=======================================================================================\n";

    return root;
}

void Preorder(Node *root)
{
    if (root == NULL)
    {
        return ;
    }
    
    cout << root->ReturnData() << " ";
    
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node *root)
{
    if (root == NULL)
    {
        return ;
    }
    
    
    Inorder(root->left);
    cout << root->ReturnData() << " ";
    Inorder(root->right);
}

void Postorder(Node *root)
{
    if (root == NULL)
    {
        return ;
    }
    
    Postorder(root->left);
    Postorder(root->right);
    cout << root->ReturnData() << " ";
}


int main()
{
    Node *root = CreateNode(); 
    cout << "Printing in Preorder traversal:\n";
    Preorder(root);
    cout << "\nPrinting in Inorder traversal:\n";
    Inorder(root);
    cout << "\nPrinting in Postorder traversal:\n";
    Postorder(root);
    return 0;
}
