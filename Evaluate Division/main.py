class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        n = len(equations)
        m = len(queries)

        adj = collections.defaultdict(list)
        valid = set()
        
        for i in range(n):
            valid.add(equations[i][0])
            valid.add(equations[i][1])
            adj[equations[i][0]].append([equations[i][1],values[i]])
            adj[equations[i][1]].append([equations[i][0],1/values[i]])

        result = [-1 for i in range(m)]

        for i in range(m):
            a = queries[i][0]
            b = queries[i][1]

            if(not a in valid):
                result[i] = -1.0
                continue

            elif(not b in valid):
                result[i] = -1.0
                continue
            
            q = deque()
            q.append([a,1.0])
            
            vis = set()
            vis.add(a)
            
            while(len(q)):
                curr , val = q.popleft()

                if(curr == b):
                    result[i] = val
                    break

                for vp in adj[curr]:
                    if(not vp[0] in vis):
                        vis.add(vp[0])
                        q.append([vp[0],val*vp[1]])

        return result