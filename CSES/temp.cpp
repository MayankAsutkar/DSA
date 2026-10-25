#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void build(vector<pair<ll,ll>> &tree,vector<ll> &arr,ll l,ll r,ll idx)
{
    // cout<<idx<<"\n";
    if(l == r)
    {
        tree[idx].second = 0;
        tree[idx].first = arr[l];
        return;
    }
    ll m = l + (r - l)/2;
    build(tree,arr,l,m,2*idx + 1);
    build(tree,arr,m+1,r,2*idx + 2);
}

ll query(vector<pair<ll,ll>> &tree,ll l,ll r,ll k,ll idx)
{
    if(l == r)
    {
        // cout<<l<<"       "<<r<<"   "<<tree[idx].first<<"\n";
        return tree[idx].first + tree[idx].second;
    }
    ll m = l + (r - l)/2;
    ll val;
    if(k <= m)
    {
        val = query(tree,l,m,k,2*idx + 1);
    }
    else
    {
        val = query(tree,m+1,r,k,2*idx + 2);
    }
    // cout<<tree[idx].second + val<<"--------------\n";
    return tree[idx].second + val;
}

void update(vector<pair<ll,ll>> &tree,ll s,ll e,ll l,ll r,ll val,ll idx)
{
    if(l > e || r < s)
    return;
    else if(s >= l && e <= r)
    {
        tree[idx].second += val;
        return;
    }
    ll m = s + (e - s)/2;
    update(tree,s,m,l,r,val,2*idx + 1);
    update(tree,m+1,e,l,r,val,2*idx + 2);
}

int main() 
{
    ll n,q;
    cin>>n>>q;
    vector<ll> arr(n);
    for(ll i = 0 ; i < n ; i++)
    cin>>arr[i];
    vector<pair<ll,ll>> tree(4*n,{0,0});
    build(tree,arr,0,n-1,0);
    // cout<<"DONE\n";
    while(q--)
    {
        ll x;
        cin>>x;
        if(x == 1)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            a--;
            b--;
            update(tree,0,n-1,a,b,c,0);
        }
        else
        {
            ll a;
            cin>>a;
            a--;
            cout<<query(tree,0,n-1,a,0)<<"\n";
        }
    }
}