#include <bits/stdc++.h>
using namespace std;
class MergeSorting
{
    public:
        void mergeSort(vector<int> &array);
        void merge(vector<int> &leftarray,vector<int> &rightarray,vector<int> &array);
};
void MergeSorting :: mergeSort(vector<int> &array)
{
    int length = array.size();
    if(length<=1)
    return;
    int middle = length/2;
    vector<int> leftarray(middle);
    vector<int> rightarray(length-middle);
    int j=0;
    for(int i=0;i<length;i++)
    {
        if(i<middle)
        leftarray[i] = array[i];
        else
        {
            rightarray[j] = array[i];
            j++;
        }
    }
    mergeSort(leftarray);   
    mergeSort(rightarray);
    merge(leftarray,rightarray,array);   
}
void MergeSorting :: merge(vector<int> &leftarray,vector<int> &rightarray,vector<int> &array)
{
    int i=0;
    int j=0;
    int x=0;
    int leftsize = leftarray.size();
    int rightsize = rightarray.size();
    int length = array.size();
    while(i < leftsize && j < rightsize)
    {
        if(leftarray[i] <= rightarray[j])
        {
            array[x] = leftarray[i];
            i++;
            x++;
        }
        else
        {
            array[x] = rightarray[j];
            j++;
            x++;
        }
    }
    while(i < leftsize)
    {
        array[x] = leftarray[i];
        i++;
        x++;
    }
    while(j < rightsize)
    {
        array[x] = rightarray[j];
        j++;
        x++;
    }
}
int main()
{
    vector<int> array = {3,1,4,6,2,7,324,72,4,2};
    MergeSorting obj;
    obj.mergeSort(array);
    int length = array.size();
    for(int i=0;i<length;i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}