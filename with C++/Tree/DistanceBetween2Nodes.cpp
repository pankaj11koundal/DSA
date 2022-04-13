// Printing the nodes at kth distance from target node
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

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    
    if (root->getData() == n1 || root->getData() == n2)
    {
        return root;
    }
    
    Node *leftLCA = LCA(root->left, n1, n2);
    Node *rightLCA = LCA(root->right, n1, n2);

    if (leftLCA && rightLCA)
    {
        return root;   
    }

    if (leftLCA != NULL)
    {
        return leftLCA;
    }
    
    return rightLCA;
}

int findDistance(Node *root, int key, int d)
{
    if (root == NULL)
    {
        return 0;
    }
    
    if (root->getData() == key)
    {
        return d;
    }

    int ld = findDistance(root->left, key, d + 1);
    if (ld)
    {
        return ld;
    }
    
    int rd = findDistance(root->right, key, d + 1);
    if (rd)
    {
        return rd;
    }
    
    return 0;
}

int distanceBetweenNodes(Node *root, int n1, int n2)
{
    int d1 = findDistance(root, n1, 0);
    int d2 = findDistance(root, n2, 0);

    return d1 + d2;
}
int main()
{
    Node *root = CreateNode();
    Node *lca = LCA(root, 8, 7);
    cout << lca->getData() << endl;
    cout << distanceBetweenNodes(lca,8, 7);
    return 0;
}

//         1
//        / \
//       2   3
//      / \ / \
//     4  5 6  7