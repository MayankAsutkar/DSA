#include<iostream>
using namespace std;
class dqueue{
    int start;
    int end;
    public:
    int arr[100000];
    dqueue()
    {
        start = 0;
        end = -1;
    }
    void popf()
    {
        end--;
    }
    void popb()
    {
        start++;
    }
    int front()
    {
        return arr[end];
    }
    int back()
    {
        return arr[start];
    }
    void push(int x)
    {
        end++;
        arr[end] = x;
    }
    bool empty()
    {
        if(start>end)
        return true;
        else
        return false;
    }
};
int main()
{
    dqueue dqueue;
    dqueue.push(1);
    dqueue.push(3);
    dqueue.push(4);
    dqueue.popf();
    dqueue.push(5);
    dqueue.push(6);
    dqueue.popb();
    
    cout<<dqueue.front()<<endl;
    cout<<dqueue.back();
}
