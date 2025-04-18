class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        n = len(senate)

        rq,dq = deque(),deque()

        for i in range(n):
            if(senate[i] == 'R'):
                rq.append(i)
            else:
                dq.append(i)
        
        while rq and dq:
            r = rq.popleft()
            d = dq.popleft()

            if(r < d):
                rq.append(r+n)
            else:
                dq.append(d+n)
        

        if(rq):
            return "Radiant"
        else:
            return "Dire"