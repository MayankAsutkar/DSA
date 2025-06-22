#include<bits/stdc++.h>
using namespace std;
class MergeSorting
{
    friend class LinkedList;
    public:
        void mergeSort(LinkedList* &head);
        void merge(LinkedList* left,LinkedList* right,LinkedList* head);
};
void MergeSorting :: mergeSort(LinkedList* &head)
{
    
}
class LinkedList
{
    friend class MergeSorting;
    private:
        int val;
        LinkedList* next;
    public:
        LinkedList(LinkedList* next,int val)
        {
            this -> next = next;
            this -> val = val;
        }
        LinkedList(int val)
        {
            this -> next = NULL;
            this -> val = val;
        }
        LinkedList()
        {
            this -> val = 0;
            this -> next = NULL;
        }
};
int main()
{
    
    return 0;
}