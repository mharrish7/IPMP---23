#User function Template for python3


class Solution:
    
    #Function to detect cycle in a directed graph.
    def isCyclic(self, V, adj):
        
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
            
        
        
        return cycle
            


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)
        
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        V,E = list(map(int, input().strip().split()))
        adj = [[] for i in range(V)]
        for i in range(E):
            a,b = map(int,input().strip().split())
            adj[a].append(b)
        ob = Solution()
        
        if ob.isCyclic(V, adj):
            print(1)
        else:
            print(0)
# } Driver Code Ends