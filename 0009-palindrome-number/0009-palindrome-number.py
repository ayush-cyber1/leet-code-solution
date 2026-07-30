class Solution:
    def isPalindrome(self, x: int) -> bool:
        # Negative numbers are never palindromes (the '-' sign breaks symmetry)
        # Numbers ending in 0 (except 0 itself) can't be palindromes either
        if x < 0 or (x % 10 == 0 and x != 0):
            return False

        reverted = 0
        while x > reverted:
            reverted = reverted * 10 + x % 10
            x //= 10

        # Even-length number: x == reverted
        # Odd-length number: middle digit doesn't matter, so drop it (reverted // 10)
        return x == reverted or x == reverted // 10