#include<bits/stdc++.h>
using namespace std;
class ListNode;
class MergeSorting
{
    friend class ListNode;
    public:
        ListNode* mergeSort(ListNode* &head);
        ListNode* merge(ListNode* left,ListNode* right);
};
ListNode* MergeSorting :: mergeSort(ListNode* &head)
{
    if(head == NULL || head -> next == NULL)
    return head;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* temp = NULL;
    while(fast!=NULL && fast -> next != NULL)
    {
        temp = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    temp -> next = NULL;
    ListNode* left = mergeSort(head);
    ListNode* right = mergeSort(slow);
    return merge(left,right);
}
ListNode* MergeSorting :: merge(ListNode* left,ListNode* right)
{
    ListNode* ans = new ListNode();
    ListNode* dummy = ans;
    while(left != NULL && right != NULL)
    {
        if(left -> val < right -> val)
        {
            dummy -> next = left;
            left = left -> next;
        }
        else
        {
            dummy -> next = right;
            right = right -> next;
        }
        dummy = dummy -> next;
    }
    if(left != NULL)
    {
        dummy -> next = left;
    }
    if(right != NULL)
    {
        dummy -> next = right;
    }
    return ans -> next;
}
class ListNode
{
    friend class MergeSorting;
    private:
        int val;
        ListNode* next;
    public:
        ListNode(ListNode* next,int val)
        {
            this -> next = next;
            this -> val = val;
        }
        ListNode(int val)
        {
            this -> next = NULL;
            this -> val = val;
        }
        ListNode()
        {
            this -> val = 0;
            this -> next = NULL;
        }
};
int main()
{
    return 0;
}