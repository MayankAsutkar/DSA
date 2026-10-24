class Solution {
public:
    using ll = long long;
    void update(vector<ll> &tree,ll l,ll r,ll val,ll ind)
    {
        if(l == r)
        {
            tree[ind]++;
            return;
        }
        ll m = l + (r - l)/2;
        if(val <= m)
        update(tree,l,m,val,2*ind + 1);
        else
        update(tree,m+1,r,val,2*ind + 2);
        tree[ind] = tree[2*ind + 1] + tree[2*ind + 2];
    } 

    ll query(vector<ll> &tree,ll s,ll e,ll l,ll r,ll ind)
    {
        if(l > r)
        return 0;
        if(l > e || r < s)
        return 0;
        if(l <= s && r >= e)
        return tree[ind];

        ll m = s + (e - s)/2;
        ll left = query(tree,s,m,l,r,2*ind + 1);
        ll right = query(tree,m+1,e,l,r,2*ind + 2);
        return left + right;
    }


    int reversePairs(vector<int>& nums) {
        ll n = nums.size();
        vector<int> vals = nums;
        vector<ll> temp;
        sort(vals.begin(),vals.end());
        temp.push_back(vals[0]);
        for(ll i = 1 ; i < vals.size() ; i++)
        {
            if(vals[i] != vals[i-1])
            temp.push_back(vals[i]);
        }
        ll m = temp.size();
        ll ans = 0;
        vector<ll> tree(4*m,0);
        for(ll i = 0 ; i < n ; i++)
        {
            auto itr = upper_bound(temp.begin(),temp.end(),2LL*nums[i]);
            if(itr == temp.end())
            {
                itr = lower_bound(temp.begin(),temp.end(),nums[i]);
                ll f = itr - temp.begin();
                update(tree,0,m-1,f,0);
                continue;
            }
            ll idx = itr - temp.begin();
            ans += query(tree,0,m-1,idx,m-1,0);
            itr = lower_bound(temp.begin(),temp.end(),nums[i]);
            ll f = itr - temp.begin();
            update(tree,0,m-1,f,0);
        }
        return ans;
    }
};