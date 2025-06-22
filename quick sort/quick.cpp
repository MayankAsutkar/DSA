#include <bits/stdc++.h>
using namespace std;
void quick(vector<int> &array,int low,int high)
{
    if(low>=high)
    return ;
    int i=low-1;
    int j = low;
    while(j <= high)
    {
        if(array[j]<=array[high])
        {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        j++;
    }
    quick(array,low,(i-1));
    quick(array,i+1,high);
}
int main()
{
    vector<int> array = {8,2,4,7,1,3,9,6,5};
    quick(array,0,array.size()-1);
    for(int i=0;i<array.size();i++)
    {
        cout<<array[i]<<"  ";
    }
    return 0;
}