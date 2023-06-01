import math

class Solution:
	def sortedArrayToBST(self, nums):
	    res = []
	    def rec(nums):
	        if len(nums) == 0:
	            return
	        if len(nums) == 1:
	            res.append(nums[0])
	            return 
	        
	        m = math.ceil(len(nums)/2) - 1
	        
	        res.append(nums[m])
	        
	        
	        
	        rec(nums[:m])
	        if m+1 < len(nums):
	            rec(nums[m+1:])
        rec(nums)
        return res
	    
	        


#{ 
 # Driver Code Starts
if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		nums = list(map(int, input().split()))
		obj = Solution()
		ans = obj.sortedArrayToBST(nums)
		for _ in ans:
			print(_, end = " ")
		print()

# } Driver Code Ends