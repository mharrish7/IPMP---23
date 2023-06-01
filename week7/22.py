import sys
sys.setrecursionlimit(100000000)
class Solution:
    # @param A : integer
    # @param B : list of list of integers
    # @return an integer
    def solve(self, V, B):
        adj = [[] for i in range(V)]
        for i in B:
            adj[i[0]-1].append(i[1]-1)
        cycle = False
        GlobalV = set()
        def dfs(i,visited):
            nonlocal cycle, GlobalV
            if i in visited:
                cycle = True 
                return 
            visited.add(i)
            for v in adj[i]:
                if v in GlobalV:
                    continue
                dfs(v,visited)
            GlobalV.add(i)
            visited.remove(i)
        
        for i in range(len(adj)):
            if i not in GlobalV:
                dfs(i,set())
            
        
        
        return 1 if cycle else 0