// C++ Program to demonstrate the implementation of the insertion in AVL Tree

# include<iostream>
#include<conio.h>

using namespace std;

class Node
{
private:
    int data;
    Node *right;
    Node *left;
    int height;

    int Height(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            return node->height;
        }
    }

    int Max(int hl, int hr)
    {
        if (hl > hr)
        {
            return hl;
        }
        else
        {
            return hr;
        }  
    }

    int bf(Node *node)
    {
        return Height(node->left) - Height(node->right);
    }

    Node *RRRotation(Node *node)
    {
        // Capturing
        Node *b = node->left;
        Node *a = b->right;
        
        // Rotation
        b->right = node;
        node->left = a;

        // Updating heights
        node->height = Max(Height(node->left), Height(node->right)) + 1;
        b->height = Max(Height(b->left), Height(b->right)) + 1;
        return b;
    }

    Node *RLRotation(Node *node)
    {
        node->right = RRRotation(node->right);
        return LLRotation(node);
    }

    Node *LLRotation(Node *node)
    {
        // Capturing
        Node *b = node->right;
        Node *a = b->left;
        
        // Rotation
        b->left = node;
        node->right = a;

        // Updating heights
        node->height = Max(Height(node->left), Height(node->right)) + 1;
        b->height = Max(Height(b->left), Height(b->right)) + 1;
        return b;
    }

    Node *LRRotation(Node *node)
    {
        node->left = LLRotation(node->left);
        return RRRotation(node);
    }

    Node *Insert(Node *node, int item)
    {
        int b;
        if (node == NULL)
        {
            // adding node
            node = new Node;
            node->data = item;
            node->height = Max(Height(node->left), Height(node->right)) + 1;           
            return node;
        }

        if (item < node->data)
        {
            node->left = Insert(node->left, item);
        }
        else
        {
            node->right = Insert(node->right, item);
        }
        
        // code for maintaining the height
        node->height = max(Height(node->left), Height(node->right)) + 1;
        b = bf(node);

        // LL Case needs RR rotation
        if (b > 1 && item < node->left->data)
        {
            return RRRotation(node);
        }
        // LR Case needs RL rotation
        else if (b > 1 && item > node->left->data)
        {
            return LRRotation(node);
        }
        // RR Case needs LL rotation
        else if (b < -1 && item > node->right->data)
        {
            return LLRotation(node);
        }
        // RL Case needs LR rotation
        else if (b < -1 && item < node->right->data)
        {
            return RLRotation(node);
        }
    
        return node;
    }

    int ReturnData(Node *node)
    {
        if (node != NULL)
            return node->data;
        else
            return 0;
    }

public:
    Node()
    {
        right = NULL;
        left = NULL;
        height = 1;
        data = 0;
    }

    Node *insertNode(Node *root, int item)
    {
        return root->Insert(root, item);
    }    

    void Display(Node *root)
    {
    string str = "";
    if (root == NULL)
    {
        return ;
    }
    
    Node *left = root->left, *right = root->right;

    Display(root->left);
    cout << "Data in the node is " << ReturnData(root) << "\n";
    cout << "data in the left node is " << ReturnData(left);
    cout << "\n data in the right node is " << ReturnData(right);
    // cout << "Height of the " << root->data << " is " << root->height << "\n";
    cout << "\nbalancing factor of " << root->data << " is " << bf(root) << "\n";
    
    cout << "-------------------------------------------------\n";
    
    Display(root->right);
    }
};


int main()
{
    // cout << "Node created";
    Node *root = NULL;
    int n;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y')
    {
        cout << "Choose any one operation from below: \n"
             << "1) Insertion\n"
             << "2) Display\n"
             << "3) Quit: ";

        cin >> n;    
        
        switch (n)
        {
        case 1:
            cout << "Enter the data you want to enter in the node: ";
            cin >> n;
            root = root->insertNode(root, n);
            cout << "Node inserted";
            break;
        
        case 2:
            cout << "The data in the node: \n";
            root->Display(root);
            break;

        case 3:
           choice = 'n';
           break;

        default:
            cout << "Please enter an valid option: ";
            break;
        }
    }
    return 0;
}
