#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void build(vector<ll> &tree,vector<ll> &arr,ll l,ll r,ll idx)
{
    if(l == r)
    {
        tree[idx] = arr[l];
        return;
    }
    ll m = l + (r - l)/2;
    build(tree,arr,l,m,2*idx + 1);     
    build(tree,arr,m+1,r,2*idx + 2);
    tree[idx] = max(tree[2*idx + 1],tree[2*idx + 2]);     
}

ll query(vector<ll> &tree,ll l,ll r,ll val,ll idx)
{
    // cout<<l<<" "<<r<<"\n";
    if(l == r && tree[idx] >= val)
    {
        tree[idx] -= val;
        return l;
    }
    else if(l == r)
    return -1;
    ll m = l + (r - l)/2;
    ll v;
    if(tree[2*idx + 1] >= val)
    v = query(tree,l,m,val,2*idx + 1);
    else if(tree[2*idx + 2] >= val)
    v = query(tree,m+1,r,val,2*idx + 2);
    else
    v = -1;
    tree[idx] = max(tree[2*idx + 1],tree[2*idx + 2]);
    return v;
}

int main() 
{
    ll n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    for(ll i = 0 ; i < n ; i++)
    cin>>arr[i];
    vector<ll> tree(4*n,0);
    build(tree,arr,0,n-1,0);
    for( ll i = 0 ; i < m ; i++)
    {
        ll val;
        cin>>val;
        cout<<query(tree,0,n-1,val,0) + 1<<" ";
        // cout<<endl; 
    }
}