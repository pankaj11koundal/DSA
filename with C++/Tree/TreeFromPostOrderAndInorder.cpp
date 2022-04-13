// Program to create an tree form postorder and inorder traversals

#include<bits/stdc++.h>

using namespace std;

class Node
{
private:
    int data;

public :
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

int search(int inorder[], int val, int start, int end)
{
    // cout << "Inside the search " << endl;
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == val)
        {
            return i;
        }
    }
    return -1;
}

Node *builtTree(int postorder[], int inorder[], int start, int end)
{
    static int idx = end;

    if (start > end)
    {
        return NULL;
    }

    int val = postorder[idx];
    idx--;
    Node *curr = new Node(val);

    if (start == end)
    {
        return curr;
    }
    
    int pos = search(inorder, val, start, end);

    curr->right = builtTree(postorder, inorder, pos + 1, end);
    curr->left = builtTree(postorder, inorder, start, pos-1);
    return curr;
}

void showTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    
    showTree(root->left);
    cout << root->getData() << " ";
    showTree(root->right);
}

int main()
{
    int n;
    cout << "Enter the size of the traversal: ";
    cin >> n;

    int postorder[n], inorder[n];
    cout << "Enter the postorder traversal: ";
    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }
    
    cout << "Enter the inorder traversal: ";
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }
    
    Node *root = builtTree(postorder, inorder, 0, n - 1);
    showTree(root);

    return 0;
}