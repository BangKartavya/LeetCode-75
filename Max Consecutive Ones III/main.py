class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        n = len(nums)
        l = 0
        r = 0

        zeros = 0
        maxi = 0

        while(r < n):
            if(nums[r] == 0):
                zeros+=1
            
            if(zeros <= k):
                maxi = max(maxi,r-l+1)
            
            else:
                while(zeros > k and l < r):
                    if(nums[l] == 0):
                        zeros-=1
                    l+=1

            r+=1

        return maxi