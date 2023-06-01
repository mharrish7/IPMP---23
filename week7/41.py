class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:        
        
        dist = [float('inf')]*(n+1) 

        Q = []
        dist[k] = 0
        heapq.heappush(Q,[0,k])
        hast = {}
        for i,j,t in times:
            if i in hast:
                hast[i].append([j,t])
            else:
                hast[i] = [[j,t]]
        while len(Q) > 0:
            d,t = heapq.heappop(Q)
            if t in hast:
                for i in hast[t]:
                    if dist[i[0]] > d + i[1]:
                        dist[i[0]] = d + i[1]
                        heapq.heappush(Q,[d+i[1],i[0]])
        dist.pop(0)
        res = max(dist)
        return res if res != float('inf') else -1
