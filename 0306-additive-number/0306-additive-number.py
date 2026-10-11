class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        n = len(num)

        def is_valid(first: int, second: int, start: int) -> bool:
            if start == n:
                return True

            total = str(first + second)

            if not num.startswith(total, start):
                return False

            return is_valid(second, first + second, start + len(total))

        for i in range(1, n):
            if num[0] == '0' and i > 1:
                break

            for j in range(i + 1, n):
                if num[i] == '0' and j > i + 1:
                    break

                first = int(num[:i])
                second = int(num[i:j])

                if is_valid(first, second, j):
                    return True

        return False