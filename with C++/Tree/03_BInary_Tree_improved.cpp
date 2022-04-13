// Improvised version of Binary search tree 

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
        if (node == NULL)
        {
            return 0;
        }
        else
        {
            return (Height(node->left) - Height(node->right));
        }
    }

    Node *Insert(Node *node, int item)
    {
        int b;
        if (node == NULL)
        {
            // adding node
            node = new Node;
            node->data = item;
            if (node->left == NULL && node->right == NULL)
            {
                node->height = 0;
            }
            else
            {
            node->height = Max(Height(node->left), Height(node->right)) + 1; 
            }            
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
        if (node == NULL)
        
        b = bf(node);

        return node;       
    }

public:
    Node()
    {
        right = NULL;
        left = NULL;
        height = 1;
    }

    Node *insertNode(Node *root, int item)
    {
        return root->Insert(root, item);
    }    

    void Display(Node *root)
    {
    if (root == NULL)
    {
        return ;
    }
    
    Display(root->left);
    cout << "Data in the node is " << root->data << "\n";
    cout << "Height of the " << root->data << " is " << root->height << "\n";
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
