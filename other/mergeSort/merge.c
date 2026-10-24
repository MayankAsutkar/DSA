#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void merge(int* left,int* right,int* arr,int l,int r,int len);
void mergeSort(int* arr,int len)
{
    if(len <= 1)
    return;
    int mid = (len)/2;
    int* left = (int*)malloc(mid*sizeof(int));
    int* right = (int*)malloc((len-mid)*sizeof(int));
    int j = 0;
    for(int i = 0 ; i < len ; i++)
    {
        if(i < mid)
        left[i] = arr[i];
        else
        {
            right[j] = arr[i];
            j++;
        }
    }
    mergeSort(left,mid);
    mergeSort(right,len-mid);
    merge(left,right,arr,mid,len-mid,len);
}

void merge(int* left,int* right,int* arr,int l,int r,int len)
{
    int i = 0;
    int j = 0;
    int x = 0;
    while(i < l && j < r)
    {
        if(left[i] <= right[j])
        {
            arr[x] = left[i];
            i++;
        }
        else
        {
            arr[x] = right[j];
            j++;
        }
        x++;
    }
    while(i < l)
    {
        arr[x] = left[i];
        i++;
        x++;
    }
    while(j < r)
    {
        arr[x] = right[j];
        j++;
        x++;
    }
}

int main()
{
    int n;
    printf("Enter the length of the array ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements you wanna sort \n");
    for(int i = 0 ; i < n ; i++)
        scanf("%d",&arr[i]);
    mergeSort(arr,n);
    for(int i = 0 ; i < n ; i++)
    printf("%d ",arr[i]);
    return 0;
}
