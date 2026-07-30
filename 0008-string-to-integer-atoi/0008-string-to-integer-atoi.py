class Solution:
    def myAtoi(self, s: str) -> int:
        i, n = 0, len(s)
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        # Step 1: skip leading whitespace
        while i < n and s[i] == ' ':
            i += 1

        if i == n:
            return 0

        # Step 2: check for sign
        sign = 1
        if s[i] == '+' or s[i] == '-':
            sign = -1 if s[i] == '-' else 1
            i += 1

        # Step 3: read digits
        num = 0
        while i < n and s[i].isdigit():
            num = num * 10 + int(s[i])
            i += 1
            # Early exit if it's already way past the limit (avoids huge number buildup)
            if num > INT_MAX + 1:
                break

        num *= sign

        # Step 4: clamp to 32-bit signed integer range
        if num < INT_MIN:
            return INT_MIN
        if num > INT_MAX:
            return INT_MAX

        return num