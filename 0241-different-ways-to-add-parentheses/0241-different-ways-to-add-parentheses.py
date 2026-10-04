class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        memo = {}

        def solve(expr: str) -> List[int]:
            if expr in memo:
                return memo[expr]

            if expr.isdigit():
                return [int(expr)]

            results = []

            for i, c in enumerate(expr):
                if c in '+-*':
                    left = solve(expr[:i])
                    right = solve(expr[i + 1:])

                    for l in left:
                        for r in right:
                            if c == '+':
                                results.append(l + r)
                            elif c == '-':
                                results.append(l - r)
                            else:
                                results.append(l * r)

            memo[expr] = results
            return results

        return solve(expression)