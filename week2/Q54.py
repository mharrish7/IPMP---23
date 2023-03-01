class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        n = len(prices)
        def rec(ind, buy, cap,dp):
            
            if ind == n:
                return 0
            
            if cap==0:
                return 0
            
            if (ind,buy,cap) in dp:
                return dp[(ind,buy,cap)]

            if buy:
                profit = max(rec(ind+1,0,cap,dp) - prices[ind], rec(ind+1,1,cap,dp))
            else:
                profit = max(rec(ind+1,1,cap-1,dp) + prices[ind], rec(ind+1,0,cap,dp))
            
            dp[(ind,buy,cap)] = profit
            return profit 
        
        return rec(0,1,2,{})

            