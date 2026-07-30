class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        memo = {}

        def dp(i: int, j: int) -> bool:
            if (i, j) in memo:
                return memo[(i, j)]

            # Base case: pattern exhausted
            if j == len(p):
                result = i == len(s)
            else:
                first_match = i < len(s) and p[j] in (s[i], '.')

                if j + 1 < len(p) and p[j + 1] == '*':
                    # Two choices: skip "x*" entirely, OR use it if first_match
                    result = dp(i, j + 2) or (first_match and dp(i + 1, j))
                else:
                    result = first_match and dp(i + 1, j + 1)

            memo[(i, j)] = result
            return result

        return dp(0, 0)