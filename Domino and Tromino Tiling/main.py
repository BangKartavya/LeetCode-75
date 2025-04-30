class Solution:
    def numTilings(self, n: int) -> int:
        dp = [1 for i in range(n+1)]
        MOD = (10**9+7)

        for i in range(n+1):
            if(i <= 2):
                dp[i] = i
            elif(i == 3):
                dp[i] = 2 * dp[i-1] + 1
            else:
                dp[i] = 2 * dp[i-1] + dp[i-3]
        

        return dp[n]%MOD