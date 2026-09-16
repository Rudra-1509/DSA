class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        profit,mini=0,prices[0]
        for i in range(1,len(prices)):
            price=prices[i]
            cur_profit=price-mini
            profit=max(profit,cur_profit)
            mini=min(mini,price)

        return profit
