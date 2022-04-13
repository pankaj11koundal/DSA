// implementation of BInary Search Tree

#include <iostream>

using namespace ::std;

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
    }

    int ReturnData()
    {
        return data;
    }
};

Node *Insert_Binary(Node *root)
{
    Node *nptr = new Node, *q = root;
    nptr->EnterData();

    while (1)
    {
        if (q->ReturnData() < nptr->ReturnData())
        {
            if (q->right == NULL)
            {
                q->right = nptr;
                break;
            }
            else
            {
                q = q->right;
            }    
        }
        else
        {
            if (q->left == NULL)
            {
                q->left = nptr;
                break;
            }
            else
            {
                q = q->left;
            }
        }   
    }
    return root;
}

void ShowNode(Node *root)
{
    // if (p == NULL)
    // {
    //     return ;
    // }
    // else
    // {
    //     cout << "The data of the node is " << p->ReturnData() << "\n";
    //     ShowNode(p->left);
    //     ShowNode(p->right);
    // }
    if (root == NULL)
    {
        return ;
    }
    
    
    ShowNode(root->left);
    cout << root->ReturnData() << " ";
    ShowNode(root->right);
}

int main()
{
    Node *root = new Node;
    root->EnterData();
    char choice;
    ShowNode(root);
    cout << "\nWant to add more nodes: ";
    cin >> choice;

    while (choice == 'y' || choice == 'Y')
    {
        root = Insert_Binary(root);
        cout << "\nWant to add more nodes: ";
        cin >> choice;
    }
    
    ShowNode(root);
    return 0;
}
