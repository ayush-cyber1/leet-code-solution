class Solution:
    def isNumber(self, s):

        n = len(s)
        i = 0

        # Optional sign
        if i < n and (s[i] == '+' or s[i] == '-'):
            i += 1

        # Digits before decimal point
        digits = 0

        while i < n and s[i].isdigit():
            i += 1
            digits += 1

        # Decimal point
        if i < n and s[i] == '.':
            i += 1

            # Digits after decimal point
            while i < n and s[i].isdigit():
                i += 1
                digits += 1

        # There must be at least one digit
        if digits == 0:
            return False

        # Exponent
        if i < n and (s[i] == 'e' or s[i] == 'E'):
            i += 1

            # Optional exponent sign
            if i < n and (s[i] == '+' or s[i] == '-'):
                i += 1

            # Exponent must contain digits
            exp_digits = 0

            while i < n and s[i].isdigit():
                i += 1
                exp_digits += 1

            if exp_digits == 0:
                return False

        # Everything must have been consumed
        return i == n