class Solution {
private:
    vector<int> prices;
    int n;
    int fee;
    
    vector<vector<int>> dp;

    int solve(int i, int transactionType) {
        if(i >= n) return 0;

        int take = 0;
        int noTake = 0;

        if(dp[i][transactionType] != -1) return dp[i][transactionType];

        if(transactionType == 0) {
            take = -prices[i] + solve(i+1,1);
        }
        else {
            take = prices[i] - fee + solve(i+1,0);
        }

        noTake = solve(i+1,transactionType);

        return dp[i][transactionType] = max(take,noTake);
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        this->prices = prices;
        n = prices.size();
        this->fee = fee;

        dp.resize(n,vector<int>(2,-1));

        return solve(0,0);
    }
};