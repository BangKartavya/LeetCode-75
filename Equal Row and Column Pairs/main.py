class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        mp = {}
        n = len(grid)
        for i in range(n):
            if(not mp.get(tuple(grid[i]),False)):
                mp[tuple(grid[i])]=1
            else:
                mp[tuple(grid[i])]+=1
        
        transpose = []

        cnt = 0

        for j in range(n):
            for i in range(n):
                transpose.append(grid[i][j])
            
            if(mp.get(tuple(transpose),False)):
                cnt += mp[tuple(transpose)]
            
            transpose = []
        

        return cnt