class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []

        def backtrack(start, current, total):
            if total == target:
                result.append(current.copy())
                return

            if total > target:
                return

            for i in range(start, len(candidates)):
                num = candidates[i]

                current.append(num)

                # i, not i + 1:
                # allows the same number to be used again
                backtrack(i, current, total + num)

                current.pop()

        backtrack(0, [], 0)

        return result