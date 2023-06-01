class Solution:
    def canFinish(self, n: int, pre: List[List[int]]) -> bool:

        indeg = [0]*n
        hast = {}
        for i,j in pre:
            if j in hast:
                hast[j].append(i)
            else:
                hast[j] = [i]

        for i in hast:
            for j in hast[i]:
                indeg[j] += 1

        Q = []
        R = []

        for i in range(len(indeg)):
            if indeg[i] == 0:
                Q.append(i)
                R.append(i)
        
        while len(Q) > 0:
            t = Q.pop()
            if t in hast:
                for i in hast[t]:
                    indeg[i] -= 1
                    if indeg[i] == 0:
                        Q.append(i)
                        R.append(i)
        
        return len(R) == n
        
        