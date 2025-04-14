class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;

        int zeros = 0;
        int maxi = 0;

        while(r < n) {
            zeros += (nums[r]==0);

            if(zeros <= 1) {
                maxi = max(maxi,r-l);
            }
            else {
                while(zeros > 1 && l < r) {
                    zeros-=(nums[l++]==0);
                }
            }
            r++;
        }

        return maxi;
    }
};