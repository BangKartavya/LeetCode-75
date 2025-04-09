class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = k-1;
        int currSum = 0;
        double avg = INT_MIN;

        for(int z=i;z<=j;z++) {
            currSum += nums[z];
        }

        while(j < n) {
            avg = max(avg,(double)currSum/(double)k);

            currSum -= nums[i];
            i++;
            j++;
            if(j < n) currSum += nums[j];
        }

        return avg;

    }
};