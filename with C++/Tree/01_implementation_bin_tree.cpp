// Program to demonstrate the implementation of the binary tree

#include<iostream>

using namespace::std;

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
        cout << "Enter the data in the node: ";
        cin >> data;
    }

    int ReturnData()
    {
        return data;
    }
};

Node *CreateNode()
{
    Node *p = new Node();
    p->EnterData();
    return p;
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
    Node *p = CreateNode();
    Node *p1 = CreateNode();
    Node *p2 = CreateNode();

    p->left = p1;
    p->right = p2;

    ShowNode(p);
    
    return 0;
}



