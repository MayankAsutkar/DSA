#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    ll n,q;
    cin>>n>>q;
    vector<vector<ll>> arr(n+1,vector<ll>(n+1,0));
    vector<vector<ll>> pref(n+1,vector<ll>(n+1,0)); 
    for(ll i = 1 ; i <= n ; i++)
    {
        ll sum = 0;
        for(ll j = 1 ; j <= n ; j++)
        {
            char c;
            cin>>c;
            if(c == '*')
            arr[i][j] = 1;
            sum += arr[i][j];
            pref[i][j] = pref[i-1][j] + sum;
        }
    }
    while(q--)
    {
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        ll ans = pref[x2][y2] - pref[x2][y1-1] - pref[x1-1][y2] + pref[x1 - 1][y1 - 1];
        cout<<ans<<"\n";
    }

}