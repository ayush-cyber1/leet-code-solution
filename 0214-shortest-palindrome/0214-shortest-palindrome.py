class Solution:
    def shortestPalindrome(self, s: str) -> str:
        if not s:
            return s

        combined = s + "#" + s[::-1]
        n = len(combined)
        lps = [0] * n

        length = 0
        i = 1
        while i < n:
            if combined[i] == combined[length]:
                length += 1
                lps[i] = length
                i += 1
            elif length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1

        overlap = lps[n - 1]
        add = s[overlap:][::-1]

        return add + s