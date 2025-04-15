class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        int total = accumulate(begin(nums),end(nums),0);
        int currSum = 0;
        
        for(int i = 0;i<n;i++) {
            if(total - currSum - nums[i] == currSum) return i;

            currSum += nums[i];
        }

        return -1;

    }
};