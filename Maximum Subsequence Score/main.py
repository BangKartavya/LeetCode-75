class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        vp = [(n2,n1) for n1,n2 in zip(nums1,nums2)]
        vp = sorted(vp,reverse=True)
        n = len(vp)
        minHeap = []
        heapq.heapify(minHeap)

        result = 0
        runningSum = 0

        for i in range(k):
            runningSum += vp[i][1]
            heappush(minHeap,vp[i][1])
        
        result = runningSum * vp[k-1][0]

        for i in range(k,n):
            runningSum -= heappop(minHeap)
            heappush(minHeap,vp[i][1])
            runningSum += vp[i][1]

            result = max(result,runningSum * vp[i][0])
        
        return result

