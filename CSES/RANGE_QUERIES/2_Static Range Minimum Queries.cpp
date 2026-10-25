#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
void build(vector<ll> &x,vector<ll> &tree,ll l, ll r,ll ind)
{
    if(l == r)
    {
        tree[ind] = x[l];
        return;
    }
    ll m = l + (r - l)/2;
    build(x,tree,l,m,2*ind + 1);
    build(x,tree,m+1,r,2*ind + 2);
    tree[ind] = min(tree[2*ind + 1],tree[2*ind + 2]);
}
 
ll query(vector<ll> &tree, ll s, ll e, ll l, ll r, ll ind)
{
    if(l > e || r < s)
    return LLONG_MAX;
    else if(s >= l && e <= r)
    return tree[ind];
    ll m = s + (e - s)/2;
    ll left = query(tree,s,m,l,r,2*ind + 1);
    ll right = query(tree,m+1,e,l,r,2*ind + 2);
    return min(left,right);
}
 
int main() 
{
    ll n,q;
    cin>>n>>q;
    vector<ll> x(n);
    for(ll i = 0 ; i < n ; i++)
    {
        cin>>x[i];
    }
    vector<ll> tree(4*n,0);
    build(x,tree,0,n-1,0);
    while(q--)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        ll ans = query(tree,0,n-1,a,b,0);
        cout<<ans<<"\n";
    }
