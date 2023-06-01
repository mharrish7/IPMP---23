class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:

        parent = [i for i in range(len(edges)+1)]
        rank = [0]*(len(edges)+1)
        def find(x):
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]

        def union(A,B):
            if rank[A] > rank[B]:
                parent[B] = A 
            elif rank[B] < rank[A]:
                parent[A] = B 
            else:
                parent[B] = A 
                rank[A] += 1 
        

        for i,j in edges:
            p1 = find(i)
            p2 = find(j)
            if p1 == p2:
                return [i,j]
            else:
                union(p1,p2)
        
        return []