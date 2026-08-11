class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        # Step 1: find the sum of the longest sequential prefix
        total = nums[0]
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1] + 1:
                total += nums[i]
            else:
                break

        # Step 2: find the smallest integer >= total that's missing from nums
        num_set = set(nums)
        while total in num_set:
            total += 1

        return total