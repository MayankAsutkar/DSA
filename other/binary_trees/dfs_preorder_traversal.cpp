#include<bits/stdc++.h>
using namespace std;
/*
    preorder Traversal : Root ➝ Left ➝ Right
        This means:
        Visit the current node first (Root)
        Recursively traverse the Left Subtree
        Recursively traverse the Right Subtree
    
            🌳 Example Tree:
            Let's take this tree:

                  1
                 / \
                2   3
                 \
                  5
                 /
                7
            🔄 Preorder Traversal Order:
            Following Root ➝ Left ➝ Right, the output will be:
            1 → 2 → 5 → 7 → 3
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

void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";    // 1. Visit root
    preorder(root->left);         // 2. Traverse left subtree
    preorder(root->right);        // 3. Traverse right subtree
}

int main()
{
    
    return 0;
}