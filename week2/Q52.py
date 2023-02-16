class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        curprice = float('inf')
        res = 0
        for i in prices:
            if i < curprice:
                curprice = i
            res = max(res, i - curprice)
        
        return res

        
        