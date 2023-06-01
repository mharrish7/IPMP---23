class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:

        hast = {}
        for j,i in richer:
            if i in hast:
                hast[i].append(j)
            else:
                hast[i] = [j]
        mini = float('inf')
        pers = -1
        def dfs(i):
            nonlocal mini,pers
            if i in visited:
                return 
            visited.add(i)
            if quiet[i] < mini:
                mini = quiet[i]
                pers = i
            if i in hast:
                for j in hast[i]:
                    if j not in visited:
                        dfs(j)
                     
            return 
        R = []
        for i in range(len(quiet)):
            visited = set()
            mini = float('inf')
            pers = -1
            dfs(i)
            R.append(pers)
        return R

            