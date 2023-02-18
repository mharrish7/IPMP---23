class Solution:
    def trap(self, height: List[int]) -> int:
        left = [0]*len(height)
        left[0] = height[0]
        for i in range(1,len(height)):
            left[i] = max(left[i-1],height[i])
        right = [0]*len(height)
        right[-1] = height[-1]
        for i in range(len(height)-2,-1,-1):
            right[i] = max(right[i+1],height[i])
        res = 0
        for i in range(1,len(height)-1):
            t = min(left[i-1],right[i+1])
            t = t - height[i]
            if t > 0:
                res += t 
        
        return res

        