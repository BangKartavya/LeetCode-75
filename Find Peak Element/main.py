class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        n = len(nums)

        s = 0
        e = n-1

        if(n == 1 or nums[0] > nums[1]): return 0

        if(nums[n-1] > nums[n-2]): return n-1

        while(s <= e):
            mid = s + (e-s)//2

            if(mid > 0 and mid < n-1 and nums[mid-1] < nums[mid] and nums[mid+1] < nums[mid]): return mid

            elif(mid > 0 and nums[mid-1] > nums[mid]): e = mid-1

            elif(mid < n-1 and nums[mid+1] > nums[mid]): s = mid+1
        
        return -1