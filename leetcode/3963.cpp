/*

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>> arr(m,vector<char>(n,'#'));
        for(int i = 0 ; i < m ; i++)
        {
            arr[i][0] = '.';
        }
        for(int i = 0 ; i < n ; i++)
        {
            arr[m-1][i] = '.';
        }
        // string s = "";
        vector<string> ans;
        for(int i = 0 ; i < m ; i++)
        {
            string temp = "";
            for(int j = 0 ; j < n ; j++)
            temp += arr[i][j];
            ans.push_back(temp);

        }
        
        return ans;
    }
};

*/