/*
    SEGMENT TREE : 

    *date - 24/10/2026 
    *lazy propagation : 

    CSES : 
    question : static range sum queries  
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void buildTree(vector<ll> &arr,vector<ll> &tree,ll ind,ll l,ll r)
{
    if(l == r)
    {
        tree[ind] = arr[l];
        return;
    }
    ll m = l + (r - l)/2;
    buildTree(arr,tree,2*ind + 1,l,m);
    buildTree(arr,tree,2*ind + 2,m + 1,r);
    tree[ind]  = tree[2*ind + 1] + tree[2*ind + 2];
} 

int query(vector<ll> &tree,ll start,ll end,ll l,ll r,ll ind)
{
    if(r < start || l > end)
    return 0;

    if(start >= l && r >= end)
    return tree[ind];

    ll m = start + (end - start)/2;
    ll left = query(tree,start,m,l,r,2*ind + 1);
    ll right = query(tree,m+1,end,l,r,2*ind + 2);
    return left + right;
}

void solve(vector<ll> &arr,ll l,ll r,vector<ll> &tree,ll s,ll e)
{
    ll ans = query(tree,s,e,l,r,0);
    cout<<ans<<"\n";
    return;
}

int main() 
{
    ll n,q;
    cin>>n>>q;
    vector<ll> arr(n);
    for(ll i = 0 ; i < n ; i++)
    cin>>arr[i];
    ll l,r;
    vector<ll> tree(4*n,0);
    buildTree(arr,tree,0,0,n-1);
    // cout<<tree[0]<<endl;
    while(q--)
    {
        cin>>l>>r;
        l--;
        r--;
        solve(arr,l,r,tree,0,n-1);
    }
    return 0;
}