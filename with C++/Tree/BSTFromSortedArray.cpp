// Program to create the binary search tree from an sorted array 
#include<iostream>

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

Node *bstFromSortedArray(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    

    int mid = (start + end) / 2;

    Node *root = new Node(arr[mid]);

    root->left = bstFromSortedArray(arr, start, mid - 1);
    root->right = bstFromSortedArray(arr, mid + 1, end);

    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->getData() << " ";
    inorder(root->right);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    Node *root = bstFromSortedArray(arr, 0, 4);

    inorder(root);
    return 0;

}