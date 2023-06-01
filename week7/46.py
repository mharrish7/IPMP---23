class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:

        n = len(grid)
        m = len(grid[0])

        visited = set()
        def dfs(i,j):
            if i < 0 or j < 0 or j >= m or i >= n:
                return False
            if (i,j) in visited:
                return False
            visited.add((i,j))
            if (i,j) == (n-1,m-1):
                return True 
            t = False 
            if grid[i][j] == 1:
                if j-1 >= 0 and grid[i][j-1] in (4,6,1):
                    t = dfs(i,j-1) 
                if j+1 < m and grid[i][j+1] in (3,5,1):
                    t = t or dfs(i,j+1)
            elif grid[i][j] == 2:
                if i-1 >= 0 and grid[i-1][j] in (3,4,2):
                    t = dfs(i-1,j) 
                if i+1 < n and grid[i+1][j] in (5,6,2):
                    t = t or dfs(i+1,j)
            elif grid[i][j] == 3:
                if i+1 < n and  grid[i+1][j] in (5,2,6):
                    t = dfs(i+1,j)
                if j-1 >= 0 and  grid[i][j-1] in (1,4,6):
                    t = t or dfs(i,j-1)
            elif grid[i][j] == 4:
                if i+1 < n and grid[i+1][j] in (5,6,2):
                    t = dfs(i+1,j)
                if j+1 < m and grid[i][j+1] in (3,5,1):
                    t = t or dfs(i,j+1)
            elif grid[i][j] == 5:
                if i-1 >= 0 and grid[i-1][j] in (3,4,2):
                    t = dfs(i-1,j) 
                if j-1 >= 0 and grid[i][j-1] in (1,4,6):
                    t = t or dfs(i,j-1)
            elif grid[i][j] == 6:
                if i-1 >= 0 and grid[i-1][j] in (3,4,2):
                    t = dfs(i-1,j) 
                if j+1 < m and grid[i][j+1] in (3,5,1):
                    t = t or dfs(i,j+1)
            
            return t 
        
        return dfs(0,0)

                