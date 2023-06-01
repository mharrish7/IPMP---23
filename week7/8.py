class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:

        def dfs(i):
            visited.add(i)
            for j in rooms[i]:
                if j not in visited:
                    dfs(j)
        
        visited = set()

        dfs(0)
        return len(visited) == len(rooms)

        