#include<bits/stdc++.h>
using namespace std;
/*

    Postorder Traversal : Left ➝ Right ➝ Root
            This means:
            Recursively traverse the Left Subtree
            Recursively traverse the Right Subtree
            Visit the Root node

            Same tree as before:
                      1
                     / \
                    2   3
                     \
                      5
                     /
                    7
            🔄 Postorder Traversal Order:
            Following Left ➝ Right ➝ Root, the output will be:
            7 → 5 → 2 → 3 → 1
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


void postorder(Node* root) {
    if (root == NULL) return;

    postorder(root->left);       // 1. Traverse left subtree
    postorder(root->right);      // 2. Traverse right subtree
    cout << root->data << " ";   // 3. Visit root
}
