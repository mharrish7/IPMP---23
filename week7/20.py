from typing import List
class Solution:
    #Function to detect cycle in an undirected graph.
	def isCycle(self, V: int, adj: List[List[int]]) -> bool:
	    
	    parent = [i for i in range(V)]
	    rank = [0]*V
	    
		def find(a):
		    if a != parent[a]:
		        parent[a] = find(parent[a])
		    
		    return parent[a]
		
		def union(a,b):
		    
		    if rank[a] > rank[b]:
		        parent[b] = a 
		    elif rank[a] < rank[b]:
		        parent[a] = b 
		    else:
		        parent[b] = a 
		        rank[a] += 1
		
		added = set()
	    for i in range(len(adj)):
	        
	        for j in adj[i]:
	            if (i,j) in added:
	                continue
	            a = find(i)
	            b = find(j)
	            if a == b:
	                return 1
	            else:
	                union(a,b)
	            added.add((i,j))
	            added.add((j,i))
	    
	    return 0


#{ 
 # Driver Code Starts
if __name__ == '__main__':

	T=int(input())
	for i in range(T):
		V, E = map(int, input().split())
		adj = [[] for i in range(V)]
		for _ in range(E):
			u, v = map(int, input().split())
			adj[u].append(v)
			adj[v].append(u)
		obj = Solution()
		ans = obj.isCycle(V, adj)
		if(ans):
			print("1")
		else:
			print("0")

# } Driver Code Ends