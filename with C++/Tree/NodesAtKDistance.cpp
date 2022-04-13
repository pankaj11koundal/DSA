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

void printSubtreeNodes(Node *root, int k)
{
    if (root == NULL || k < 0)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->getData() << " ";
    }

    printSubtreeNodes(root->left, k - 1);
    printSubtreeNodes(root->right, k - 1);
}

int nodesAtDistanceK(Node *root, Node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root == target)
    {
        printSubtreeNodes(root, k);
        return 0;
    }

    int ld = nodesAtDistanceK(root->left, target, k);
    if (ld != -1)
    {
        if (ld + 1 == k)
        {
            cout << root->getData() << " ";
        }
        else
        {
            printSubtreeNodes(root->right, k - ld - 2);
        }
        return ld + 1;
    }

    int rd = nodesAtDistanceK(root->right, target, k);
    if (rd != -1)
    {
        if (rd + 1 == k)
        {
            cout << root->getData() << " ";
        }
        else
        {
            printSubtreeNodes(root->left, k - rd - 2);
        }
        return rd + 1;
    }

    return -1;
}

int main()
{
    Node *root = CreateNode();
    nodesAtDistanceK(root, root->left->left, 3);
    return 0;
}

//         1
//        / \
//       2   3
//      / \ / \
//     4  5 6  7
//    / \/ \
//   8  910 11