#User function Template for python3
class Solution:

	def findSum(self,a, b):
		
		s1 = []
		s2 = []
		
		res = []
		
		for i in a:
		    s1.append(i)
		
		for i in b:
		    s2.append(i)
		    
		c = 0
		while(a!=[] or b!=[]):
		    a1,b1 =0,0
		    if(a!=[]):
		        a1 = a.pop()
		    
		    
		    if(b!=[]):
		        b1 = b.pop()
		    
		    s = a1 + b1 + c
		    c = s//10 
		    
		    res.append(s%10)
	   
	    if c!=0:
	       res.append(c)
	   
	   
	    return res[::-1]
		        


#{ 
 # Driver Code Starts
#Initial Template for Python 3



if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, m = list(map(int, input().strip().split()))
        a = list(map(int, input().strip().split()))
        b = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findSum(a, b)
        for i in ans:
            print(i, end=" ")
        print()
        tc -= 1

# } Driver Code Ends