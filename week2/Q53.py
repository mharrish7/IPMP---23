class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min,max = prices[0],prices[0]
        res = 0

        for i in prices:

            if i > max:
                max = i

            if i < max:
                res += (max - min)
                min = i
                max = i 
        
        res += (max - min)

        return res