class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        hold = float('-inf')
        sold = 0
        rest = 0

        for price in prices:
            prev_sold = sold
            sold = hold + price
            hold = max(hold, rest - price)
            rest = max(rest, prev_sold)

        return max(sold, rest)