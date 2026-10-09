class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        left_remove = 0
        right_remove = 0

        for c in s:
            if c == '(':
                left_remove += 1
            elif c == ')':
                if left_remove > 0:
                    left_remove -= 1
                else:
                    right_remove += 1

        result = set()

        def dfs(index, left_count, right_count, left_rem, right_rem, path):
            if index == len(s):
                if left_rem == 0 and right_rem == 0:
                    result.add(''.join(path))
                return

            c = s[index]

            if c == '(' and left_rem > 0:
                dfs(index + 1, left_count, right_count, left_rem - 1, right_rem, path)
            if c == ')' and right_rem > 0:
                dfs(index + 1, left_count, right_count, left_rem, right_rem - 1, path)

            path.append(c)
            if c != '(' and c != ')':
                dfs(index + 1, left_count, right_count, left_rem, right_rem, path)
            elif c == '(':
                dfs(index + 1, left_count + 1, right_count, left_rem, right_rem, path)
            elif right_count < left_count:
                dfs(index + 1, left_count, right_count + 1, left_rem, right_rem, path)
            path.pop()

        dfs(0, 0, 0, left_remove, right_remove, [])

        return list(result)