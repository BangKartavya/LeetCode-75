class Solution {
private:
    string word1;
    string word2;
    int n;
    int m;

    vector<vector<int>> dp;

    int solve(int i, int j) {
        if(i < 0) return j+1;
        if(j < 0) return i+1;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) return dp[i][j] = solve(i-1,j-1);

        int insert = 1 + solve(i,j-1);
        int del = 1 + solve(i-1,j);
        int replace = 1 + solve(i-1,j-1);

        return dp[i][j] = min({insert,del,replace});
    }
public:
    int minDistance(string word1, string word2) {
        this->word1 = word1;
        this->word2 = word2;
        n = word1.size();
        m = word2.size();
        
        dp.resize(n,vector<int>(m,-1));

        return solve(n-1,m-1);
    }
};