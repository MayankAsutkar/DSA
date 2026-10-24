#include <bits/stdc++.h>
using namespace std;

/*
    *traversals: It's a process of visting every node in the tree in a specific order.

    *dfs(depth first search):
        1>preorder Traversal : Root ➝ Left ➝ Right
            This means:
            Visit the current node first (Root)
            Recursively traverse the Left Subtree
            Recursively traverse the Right Subtree
        
        2>Inorder Traversal : Left ➝ Root ➝ Right
            This means:
            Recursively traverse the Left Subtree
            Visit the Root node
            Recursively traverse the Right Subtree
        
        3>Postorder Traversal : Left ➝ Right ➝ Root
            This means:
            Recursively traverse the Left Subtree
            Recursively traverse the Right Subtree
            Visit the Root node

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
int main()
{

    return 0;
}