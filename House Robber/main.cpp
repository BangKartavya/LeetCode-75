class Solution {
private:
    vector<int> dp;
    vector<int> nums;
    int n;

    int solve(int i) {
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int take = nums[i] + solve(i+2);
        int noTake = solve(i+1);

        return dp[i] = max(take,noTake);
    }

public:
    int rob(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        dp.resize(n,-1);
        return solve(0);
    }
};