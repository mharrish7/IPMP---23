class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        dp = [-1]*len(graph)
        res = []

        def dfs(i,visited):
            if i in visited:
                return False 
            visited.add(i)
            t = True
            for v in graph[i]:
                if dp[v] != -1:
                    t = t and dp[v]
                else:
                    t = t and dfs(v,visited)
            dp[i] = 1 if t else 0
            visited.remove(i)
            return t

            
        
        for i in range(len(graph)):
            if dp[i] != -1:
                if dp[i] == 1:
                    res.append(i)
            else:
                if dfs(i,set()):
                    res.append(i)
        print(dp)
        return res