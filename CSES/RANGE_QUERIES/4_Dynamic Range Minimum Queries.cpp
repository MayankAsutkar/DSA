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
    tree[idx] = min(tree[2*idx + 1],tree[2*idx + 2]);
}

ll query(vector<ll> &tree,ll s,ll e,ll l,ll r,ll idx)
{
    if(l > e || r < s)
    return LLONG_MAX;
    if(l <= s && e <= r)
    return tree[idx];
    ll m = s + (e - s)/2;
    ll left = query(tree,s,m,l,r,2*idx + 1);
    ll right = query(tree,m+1,e,l,r,2*idx + 2);
    return min(left,right);
}

void update(vector<ll> &tree,ll l,ll r,ll k,ll u,ll idx)
{
    if(l == r)
    {
        tree[idx] = u;
        return;
    }
    ll m = l + (r - l)/2;
    if(k <= m)
    update(tree,l,m,k,u,2*idx + 1);
    else
    update(tree,m+1,r,k,u,2*idx + 2);
    tree[idx] = min(tree[2*idx + 1],tree[2*idx + 2]);
}

int main() 
{
    ll n,q;
    cin>>n>>q;
    vector<ll> arr(n);
    for(ll i = 0 ; i < n ; i++)
    cin>>arr[i];
    vector<ll> tree(4*n,0);
    build(tree,arr,0,n-1,0);
    while(q--)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        if(x == 1)
        {
            y--;
            update(tree,0,n-1,y,z,0);
        }
        else
        {
            y--;
            z--;
            cout<<query(tree,0,n-1,y,z,0)<<"\n";
        }
    }
}