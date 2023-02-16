class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        res = 0
        s = 0
        for i in range(len(nums)):
            if i == 0:
                s = nums[i]
            else:
                if(nums[i-1] >= nums[i]):
                    if s > res:
                        res = s 
                    s = nums[i]
                else:
                    s += nums[i]
        if s > res:
            res = s
        return res
            