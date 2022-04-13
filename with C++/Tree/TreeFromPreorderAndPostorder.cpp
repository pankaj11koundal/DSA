// Program to create a binary tree using the preorder and inorder traversal

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

    int getNode()
    {
        return data;
    }
};

int search(int inorder[], int val, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == val)
        {
            return i;
        }
    }
    return -1;
}

Node *buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }
    int val = preorder[idx];
    idx++;
    Node *root = new Node(val);

    if(start == end)
    {
        return root;
    }

    int pos = search(inorder, val, start, end);
    root->left = buildTree(preorder, inorder, start, pos - 1);
    root->right = buildTree(preorder, inorder, pos + 1, end);
    // cout << root->left << "<-" << root << "->" << root->right << endl;
    return root;
}

void showTree(Node *root)
{
    // cout << root;
    if(root == NULL)
    {
        return;
    }
    showTree(root->left);
    cout << root->getNode() << " ";
    showTree(root->right);
}

int main()
{
    Node *root;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int inorder[n], preorder[n];
    cout << "Enter the preorder Traversal: ";
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }
    
    cout << "Enter the inorder traversal: ";
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }
    
    root = buildTree(preorder, inorder, 0, n - 1);
    showTree(root);
    return 1;
}