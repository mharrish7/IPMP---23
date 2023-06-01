class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        parent = [i for i in range(len(isConnected))]
        rank = [0]*(len(isConnected))
        def find(a):
            if a != parent[a]:
                parent[a] = find(parent[a])
            return parent[a]
        

        def union(a,b):
            if rank[a] > rank[b]:
                parent[b] = a
            elif rank[a] < rank[b]:
                parent[a] =  b 
            else:
                rank[a] += 1
                parent[b] =a  
        
        for i in range(len(isConnected)):
            for j in range(i,len(isConnected[0])):
                if isConnected[i][j] == 1:
                    p1 = find(i)
                    p2 = find(j)
                    if p1 != p2:
                        union(p1,p2)
        s = set()
        for i in parent:
            s.add(find(i))
        
        return len(s)