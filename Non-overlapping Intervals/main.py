class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        n = len(intervals)

        intervals = sorted(intervals,key=lambda x: x[1])

        nonOver = 0
        prevEnd = -10**9

        for i in range(n):
            if(intervals[i][0] >= prevEnd):
                nonOver+=1
                prevEnd = intervals[i][1]
        
        return n - nonOver