class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        pairs = {
            ')': '(',
            ']': '[',
            '}': '{'
        }

        for char in s:
            if char in pairs:
                # Closing bracket: check it matches the most recent open one
                if not stack or stack[-1] != pairs[char]:
                    return False
                stack.pop()
            else:
                # Opening bracket: push onto stack
                stack.append(char)

        # Valid only if every opening bracket was matched
        return not stack