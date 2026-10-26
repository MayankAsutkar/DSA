/*


class Solution {
public:
    using ll = long long;
    int countIslands(vector<vector<int>>& grid, int k) {
        ll m = grid.size(),n = grid[0].size();
        ll ans = 0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(ll i = 0 ; i < m ; i++)
        {
            for(ll j = 0 ; j < n;  j++)
            {
                if(vis[i][j] || !grid[i][j])
                continue;
                queue<pair<ll,ll>> que;
                vis[i][j] = true;
                que.push({i,j});
                ll temp = 0;
                while(!que.empty())
                {
                    pair<ll,ll> p = que.front();
                    ll x = p.first,y = p.second;
                    temp += grid[x][y];
                    que.pop();
                    ll x1 = x,y1 = y - 1;
                    if(x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && grid[x1][y1] && !vis[x1][y1])
                    {
                        que.push({x1,y1});
                        vis[x1][y1] = true;
                    }
                    x1 = x,y1 = y + 1;
                    if(x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && grid[x1][y1] && !vis[x1][y1])
                    {
                        que.push({x1,y1});
                        vis[x1][y1] = true;
                    }
                    x1 = x - 1,y1 = y;
                    if(x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && grid[x1][y1] && !vis[x1][y1])
                    {
                        que.push({x1,y1});
                        vis[x1][y1] = true;
                    }
                    x1 = x + 1,y1 = y;
                    if(x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && grid[x1][y1] && !vis[x1][y1])
                    {
                        que.push({x1,y1});
                        vis[x1][y1] = true;
                    }
                }
                if(temp%k == 0)
                ans++;
            }
        }
        return ans;
    }
};


*/