class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            vector<int> result(n, 0);
            int zeros = 0;

            for(int& i : nums) {
                zeros += i == 0;
            }

            if(zeros > 1) return result;

            long long prod = 1;
            int zeroIdx = -1;

            for(int i = 0; i < n; i++) {
                if(nums[i] == 0) {
                    zeroIdx = i;
                } else prod *= nums[i];
            }

            if(zeroIdx != -1) {
                result[zeroIdx] = prod;
                return result;
            } else {
                for(int i = 0; i < n; i++) {
                    result[i] = prod / nums[i];
                }
                return result;
            }
        }
};