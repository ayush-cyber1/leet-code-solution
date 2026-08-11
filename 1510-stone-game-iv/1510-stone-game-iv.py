class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        # dp[i] = True if the player to move, with i stones remaining, wins
        dp = [False] * (n + 1)

        for i in range(1, n + 1):
            j = 1
            while j * j <= i:
                # If opponent loses after we take j*j stones, we win
                if not dp[i - j * j]:
                    dp[i] = True
                    break
                j += 1

        return dp[n]