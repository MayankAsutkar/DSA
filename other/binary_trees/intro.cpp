#include <bits/stdc++.h>
using namespace std;
/*
        Binary tree is the tree in which node has no more than two children.

        Binary Tree: Binary tree is a fundamental hierarchical data structure in computer science that comprises nodes arranged in a tree-like structure. It consists of nodes, where each node can have at most two children nodes, known as the left child and the right child.

        Root Node: is the topmost node of a binary tree from which all other nodes stem out. This serves as the entry point for traversing the tree structure.

        Children Nodes are the nodes directly connected to a parent node. In a binary tree, a parent node can have zero, one or two children nodes, each situated to the left or right of the parent node.

        Leaf Nodes are the nodes that do not have any children. These nodes lie on the outermost ends of the tree branches and are the terminal points of the traversal.

        Ancestors in a Binary Tree are those nodes that lie on the path from a particular node to the root node. They are the nodes encountered while moving upwards from a specific node through its parent nodes until reaching the root of the tree.

        Full Binary Tree:
        A Full Binary Tree, also known as a Strict Binary Tree, adheres to the structural property where every node has either zero or two children.
        No node of this tree has just a single child, all internal nodes have exactly two children or in the case of leaf nodes, no children.

        Binary search tree:
            in binary search tree the left child is always less than the parent node.
            and the right child is always greater than the parent node.

        The time complexity to find an element in a tree is log n.
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
int main()
{
    Node root(1);
    root.left = new Node(2); 
    root.right = new Node(3);
    root.left -> right = new Node(5);
    root.left -> right -> left = new Node(7);
    return 0;
}