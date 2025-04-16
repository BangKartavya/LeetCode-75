class Solution {
    public:
        int equalPairs(vector<vector<int>>& grid) {
            int n = grid.size();
            int cnt = 0;

            map<vector<int>, int> mp;

            for(int i = 0; i < n; i++) {
                mp[grid[i]]++;
            }

            vector<int> transpose;

            for(int j = 0; j < n; j++) {
                for(int i = 0; i < n; i++) {
                    transpose.push_back(grid[i][j]);
                }

                if(mp.find(transpose) != mp.end()) {
                    cnt += mp[transpose];
                }
                transpose.clear();
            }

            return cnt;
        }
};