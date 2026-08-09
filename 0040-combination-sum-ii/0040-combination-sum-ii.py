class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []

        candidates.sort()

        def backtrack(start, current, total):
            if total == target:
                result.append(current.copy())
                return

            if total > target:
                return

            for i in range(start, len(candidates)):

                # Skip duplicate numbers at the same level
                if i > start and candidates[i] == candidates[i - 1]:
                    continue

                # Since array is sorted, no need to continue
                if total + candidates[i] > target:
                    break

                current.append(candidates[i])

                # i + 1 because each number can be used only once
                backtrack(i + 1, current, total + candidates[i])

                current.pop()

        backtrack(0, [], 0)

        return result