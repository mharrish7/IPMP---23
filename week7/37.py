class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:

        Q = []
        visited = set()

        n = len(grid)
        m = len(grid[0])

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    visited.add((i,j))
                    Q.append((i,j))
        if len(Q) == 0 or len(Q) == n*m:
            return -1
        dire = [[0,1],[1,0],[-1,0],[0,-1]]
        d = 0
        while len(Q) > 0:
            t = len(Q)
            for i in range(t):
                i,j = Q.pop(0)
                for x,y in dire:
                    x1,y1 = x+i,y+j 
                    if x1 < 0 or y1 < 0 or  x1 >= n or y1 >=m or (x1,y1) in visited:
                        continue 
                    Q.append((x1,y1))
                    visited.add((x1,y1))

            d+=1 

        return d-1

