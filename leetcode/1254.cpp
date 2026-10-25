/*



class Solution {
public:
    using ll = long long;
    int closedIsland(vector<vector<int>>& grid) {
        ll n = grid.size();
        ll m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        ll ans = 0;
        for(ll i = 0 ; i < n ; i++)
        {
            for(ll j = 0 ; j < m ; j++)
            {
                bool b = false;
                if(vis[i][j] || grid[i][j] == 1)
                continue;
                queue<pair<ll,ll>> que;
                que.push({i,j});
                vis[i][j] = true;
                while(!que.empty())
                {
                    pair<ll,ll> p = que.front();
                    ll x = p.first;
                    ll y = p.second;
                    que.pop();
                    if(x == 0 || x == n-1 || y == 0 || y == m-1)
                    b = true;
                    ll x1 = x - 1;
                    ll y1 = y;
                    if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && grid[x1][y1] == 0 && !vis[x1][y1])
                    {
                        que.push({x1,y1});
                        vis[x1][y1] = true;   
                    }
                    
                    x1 = x + 1;
                    y1 = y;
                    if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && grid[x1][y1] == 0 && !vis[x1][y1])
                    {
                        que.push({x1,y1});
                        vis[x1][y1] = true;   
                    }
                    x1 = x;
                    y1 = y - 1;
                    if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && grid[x1][y1] == 0 && !vis[x1][y1])
                    {
                        que.push({x1,y1});
                        vis[x1][y1] = true;   
                    }
                    x1 = x;
                    y1 = y + 1;
                    if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && grid[x1][y1] == 0 && !vis[x1][y1])
                    {
                        que.push({x1,y1});
                        vis[x1][y1] = true;   
                    }
                }
                if(!b)
                ans++;
            }
        }
        return ans;
    }
};



*/