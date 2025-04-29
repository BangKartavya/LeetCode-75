class Solution {
private:
    vector<int> dp;
    vector<int> cost;
    int n;

    int solve(int i) {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int ones = cost[i] + solve(i+1);
        int twos = cost[i] + solve(i+2);

        return dp[i] = min(ones,twos);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        this->cost = cost;
        n = cost.size();

        dp.resize(n,-1);
        int first = solve(0);

        dp.resize(n,-1);
        int second = solve(1);

        return min(first,second);
    }
};