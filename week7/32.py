class Solution:
    def findOrder(self, n: int, pre: List[List[int]]) -> List[int]:
        hast = {}
        indeg = [0]*n

        for i,j in pre:
            if j in hast:
                hast[j].append(i)
            else:
                hast[j] = [i]
        
        for i in hast:
            for j in hast[i]:
                indeg[j] += 1 
        
        R = []
        Q = []

        for i in range(len(indeg)):
            if indeg[i] == 0:
                R.append(i)
                Q.append(i)
        
        while len(Q) > 0:
            t = Q.pop()
            if t in hast:
                for i in hast[t]:
                    indeg[i] -= 1 
                    if indeg[i] == 0:
                        Q.append(i)
                        R.append(i)

        return R if len(R) == n else []