class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        int i = 0;
        int j = n-1;

        int cnt = 0;
        
        while(i < j) {
            int sum = nums[i] + nums[j];

            if(sum > k) {
                j--;
            }
            else if(sum < k) {
                i++;
            }
            else {
                cnt++;
                i++;
                j--;
            }
        }
        
        return cnt;
    }
};