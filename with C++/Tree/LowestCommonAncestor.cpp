// Program to find the lowest common ancestor of a root in the tree

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
    if(root == NULL)
    {
        return NULL;
    }
    if(root->getData() == n1 || root->getData() == n2)
    {
        return root;
    }

    Node *leftLCA = LCA(root->left, n1, n2);
    Node* rightLCA = LCA(root->right, n1, n2);

    if(leftLCA && rightLCA)
    {
        return root;
    }

    if (leftLCA != NULL)
    {
        return leftLCA;
    }

    return rightLCA;
}

bool getPath(Node *root, int key, vector<int> &path)
{
    if(root == NULL)
    {
        return false;
    }

    path.push_back(root->getData());

    if(root->getData() == key)
    {
        return true;
    }
    
    if(getPath(root->left, key, path) || getPath(root->right, key, path))
    {
        return true;
    } 
    path.pop_back();
    return false;
}

int LCA2(Node *root, int n1, int n2)
{
    vector<int> path1;
    vector<int> path2;

    if(!getPath(root, n1, path1) || !getPath(root, n2, path2))
    {
        return -1;
    }

    int cp, n;

    for (int cp = 0; cp < path1.size() && path2.size(); cp++)
    {
        if (path1[cp] != path2[cp])
        {
            n = cp - 1;
            break;
        }
    }
    
    return path1[n];
}

int main()
{
    Node *root = CreateNode();
    int n1, n2;
    cout << "Enter the first nodes whose common ancestor you want to find: ";
    cin >> n1;
    cout << "Enter the second nodes whose common ancestor you want to find: ";
    cin >> n2;
    Node *n = LCA(root, n1, n2);
    if (n != NULL)
    {
        cout << n->getData();
    }
    else{
        cout << "lowest common anscetor does not exits";
    }
    return 0;
}