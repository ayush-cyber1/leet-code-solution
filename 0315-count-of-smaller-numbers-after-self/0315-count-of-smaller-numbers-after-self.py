class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        sorted_vals = sorted(set(nums))
        rank = {v: i + 1 for i, v in enumerate(sorted_vals)}
        size = len(sorted_vals)
        tree = [0] * (size + 1)

        def update(i: int) -> None:
            while i <= size:
                tree[i] += 1
                i += i & (-i)

        def query(i: int) -> int:
            total = 0
            while i > 0:
                total += tree[i]
                i -= i & (-i)
            return total

        result = [0] * len(nums)

        for i in range(len(nums) - 1, -1, -1):
            r = rank[nums[i]]
            result[i] = query(r - 1)
            update(r)

        return result