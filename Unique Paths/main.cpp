class Solution {
    private:
        int m;
        int n;
        vector<vector<int>> dp;

        int solve(int i, int j) {
            if(i == m - 1 && j == n - 1) return 1;
            if(i >= m || j >= n) return 0;

            if(dp[i][j] != -1) return dp[i][j];

            return dp[i][j] = solve(i + 1, j) + solve(i, j + 1);
        }

    public:
        int uniquePaths(int m, int n) {
            this->m = m;
            this->n = n;
            dp.resize(m, vector<int>(n, -1));
            return solve(0, 0);
        }
};