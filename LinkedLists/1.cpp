#include<bits/stdc++.h>
using namespace std;

/*
    where is linked list used :
    1>stack and queue are some data structures where linked lists is used.
    --in real life it is always used in a browser.

    1D LINKED LISTS: 
    --> in 1D linked ists we keep track of only next element and ignore the previous element i.e. in one direction


*/
class Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1)
    {
        data = data1;
        next = next1;
    }

    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
int main()
{
    vector<int> arr = {2,5,8,7};
    Node* y = new Node(arr[0],nullptr);
    Node x = Node(arr[0],nullptr);
    cout<<y<<endl;
    cout<<x.data<<endl;
    cout<<y -> data<<endl;
}
