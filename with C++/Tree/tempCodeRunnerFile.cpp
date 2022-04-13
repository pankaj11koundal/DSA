//         1
//        / \
//       2   3
//      / \ / \
//     4  5 6  7
//    / \/ \
//   8  910 11
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