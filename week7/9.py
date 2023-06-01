class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        
        visited = set()
        
        
        
        n = len(isConnected)
        
        def bfs(i):
            Q = [i]
            while len(Q)>0:
                i = Q.pop()
                visited.add(i)
                for j in range(n):
                    if isConnected[i][j]==1 and j not in visited:
                        Q.append(j)
                    
                    
        
        
        res = 0
        for i in range(n):
            if i not in visited:
                bfs(i)
                res+=1
        return res