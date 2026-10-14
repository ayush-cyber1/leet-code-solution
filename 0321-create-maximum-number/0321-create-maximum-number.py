class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        def pick(nums, t):
            drop = len(nums) - t
            stack = []
            for num in nums:
                while drop and stack and stack[-1] < num:
                    stack.pop()
                    drop -= 1
                stack.append(num)
            return stack[:t]

        def merge(a, b):
            result = []
            i = j = 0
            while i < len(a) or j < len(b):
                if a[i:] > b[j:]:
                    result.append(a[i])
                    i += 1
                else:
                    result.append(b[j])
                    j += 1
            return result

        best = []
        m, n = len(nums1), len(nums2)

        for i in range(max(0, k - n), min(k, m) + 1):
            candidate = merge(pick(nums1, i), pick(nums2, k - i))
            if candidate > best:
                best = candidate

        return best