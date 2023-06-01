#User function Template for python3

class Solution:
    def findOrder(self,d, N, K):
        indeg = [0]*K
        hast = {}

        for i in range(1,len(d)):
            j = 0 
            while j < min(len(d[i]),len(d[i-1])) and d[i][j] == d[i-1][j]:
                j+=1 
            if j >= min(len(d[i]),len(d[i-1])):
                continue
            
            if d[i-1][j] not in hast:
                hast[d[i-1][j]] = [d[i][j]]
            else:
                hast[d[i-1][j]].append(d[i][j])
        
        for i in hast:
            for j in hast[i]:
                indeg[ord(j) - ord('a')] += 1
        
        Q = []
        R = []
        for i in range(K):
            if indeg[i] == 0:
                R.append(chr(ord('a') + i))
                Q.append(chr(ord('a') + i))
                 
        
        while len(Q) > 0:
            t = Q.pop()
            if t in hast:
                for j in hast[t]:
                    indeg[ord(j)-ord('a')] -= 1
                    if indeg[ord(j)-ord('a')] == 0:
                        Q.append(j)
                        R.append(j)
        
        return R




#{ 
 # Driver Code Starts
#Initial Template for Python 3

class sort_by_order:
    def __init__(self,s):
        self.priority = {}
        for i in range(len(s)):
            self.priority[s[i]] = i
    
    def transform(self,word):
        new_word = ''
        for c in word:
            new_word += chr( ord('a') + self.priority[c] )
        return new_word
    
    def sort_this_list(self,lst):
        lst.sort(key = self.transform)

if __name__ == '__main__':
    t=int(input())
    for _ in range(t):
        line=input().strip().split()
        n=int(line[0])
        k=int(line[1])
        
        alien_dict = [x for x in input().strip().split()]
        duplicate_dict = alien_dict.copy()
        ob=Solution()
        order = ob.findOrder(alien_dict,n,k)
        s = ""
        for i in range(k):
            s += chr(97+i)
        l = list(order)
        l.sort()
        l = "".join(l)
        if s != l:
            print(0)
        else:
            x = sort_by_order(order)
            x.sort_this_list(duplicate_dict)
            
            if duplicate_dict == alien_dict:
                print(1)
            else:
                print(0)


# } Driver Code Ends