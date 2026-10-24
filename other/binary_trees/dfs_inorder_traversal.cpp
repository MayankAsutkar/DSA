#include<bits/stdc++.h>
using namespace std;

/*
    Inorder Traversal : Left ➝ Root ➝ Right
        This means:
        Recursively traverse the Left Subtree
        Visit the Root node
        Recursively traverse the Right Subtree

        🌳 Example Tree:
                  1
                 / \
                2   3
                 \
                  5
                 /
                7
        🔄 Inorder Traversal Order:
        Following Left ➝ Root ➝ Right, the output will be:
        2 → 7 → 5 → 1 → 3

        If your tree was:
                      4
                     / \
                    2   6
                   / \ / \
                  1  3 5  7
        The inorder output would be:
        1 → 2 → 3 → 4 → 5 → 6 → 7
*/
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);        // 1. Traverse left subtree
    cout << root->data << " ";  // 2. Visit root
    inorder(root->right);       // 3. Traverse right subtree
}
