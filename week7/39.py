
class Solution:
    def isBipartite(self, gr: List[List[int]]) -> bool:
        
        colour = [0]*len(gr)
         
        for i in range(len(gr)):
            if colour[i] != 0:
                continue
            Q = [i]
            colour[i] = 1
            while len(Q) > 0:
                t = Q.pop(0)
                for i in gr[t]:
                    if colour[i] == 0:
                        colour[i] = -colour[t]
                        Q.append(i)
                    else:
                        if colour[i] == colour[t]:
                            return False 

        return True