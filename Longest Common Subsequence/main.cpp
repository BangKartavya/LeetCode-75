class Solution {
private:
    string text1;
    string text2;
    int n;
    int m;

    vector<vector<int>> dp;

    int solve(int i, int j) {
        if(i >= n || j >= m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]) {
            return 1 + solve(i+1,j+1);
        }

        return dp[i][j] = max(solve(i+1,j),solve(i,j+1));
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        this->text1 = text1;
        this->text2 = text2;

        n = text1.size();
        m = text2.size();

        dp.resize(n,vector<int>(m,-1));

        return solve(0,0);
    }
};