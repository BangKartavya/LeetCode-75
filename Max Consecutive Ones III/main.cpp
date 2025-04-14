class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n = nums.size();
            int l = 0;
            int r = 0;

            int zeros = 0;
            int maxi = 0;

            while(r < n) {
                zeros += (nums[r] == 0);

                if(zeros <= k) {
                    maxi = max(maxi, r - l + 1);
                } else {
                    while(zeros > k && l < r) {
                        zeros -= (nums[l++] == 0);
                    }
                }
                r++;
            }

            return maxi;
        }
};