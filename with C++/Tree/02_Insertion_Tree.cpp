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

Node *ShowNode(Node *p)
{
    if (p == NULL)
    {
        return p;
    }
    else
    {
        cout << "The data of the node is " << p->ReturnData() << "\n";
        ShowNode(p->left);
        ShowNode(p->right);
    }  
}

int main()
{
    Node *root = CreateNode(); 
    root = ShowNode(root);
    return 0;
}
