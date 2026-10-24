#include<bits/stdc++.h>
using namespace std;

/*
        *bfs(binary first search): 
        BFS (Breadth-First Search), also known as Level Order Traversal, visits all nodes level by level, from left to right.
              1
             / \
            2   3
             \
              5
             /
            7
        🔄 BFS Traversal Output:
        1 → 2 → 3 → 5 → 7
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

void bfs(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}


int main()
{
    return 0;
}