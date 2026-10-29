/*

// minimum XOR Path in a Grid 

class Solution {
public:
    using ll = long long;
    int minCost(vector<vector<int>>& arr) {
        ll m = arr.size();
        ll n = arr[0].size();
        vector<vector<vector<ll>>> s(m,vector<vector<ll>>(n,vector<ll>(1024,-1)));
        ll x = arr[0][0];
        s[0][0][x] = 1;
        for(ll i = 1 ; i < m ; i++)
        {
            x = (x^arr[i][0]);
            s[i][0][x] = 1;
        }
        x = arr[0][0];
        for(ll i = 1 ; i < n; i++)
        {
            x = (x^arr[0][i]);
            s[0][i][x] = 1;
        }
        for(ll i = 1 ; i < m ; i++)
        {
            for(ll j = 1 ; j < n ; j++)
            {
                for(ll k = 0 ; k < 1024 ; k++)
                {
                    ll x = s[i][j-1][k];
                    if(x == -1)
                    continue;
                    ll y = (k^arr[i][j]);
                    s[i][j][y] = 1;
                }
                for(ll k = 0 ; k < 1024 ; k++)
                {
                    ll x = s[i-1][j][k];
                    if(x == -1)
                    continue;
                    ll y = (k^arr[i][j]);
                    s[i][j][y] = 1;
                }
            }
        }

        ll mi = LLONG_MAX;
        for(ll i = 0 ; i < 1024 ; i++)
        {
            if(s[m-1][n-1][i] != -1)
            mi = min(mi,i);
            // cout<<s[m-1][n-1][i]<<" ";
        }
        // cout<<"\n";

        return mi;
    }   
};

*/