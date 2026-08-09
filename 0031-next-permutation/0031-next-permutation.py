class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        # Step 1: Find the first decreasing element from the right
        i = len(nums) - 2

        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1

        # Step 2: If such an element exists, find the next larger element
        if i >= 0:
            j = len(nums) - 1

            while nums[j] <= nums[i]:
                j -= 1

            # Swap them
            nums[i], nums[j] = nums[j], nums[i]

        # Step 3: Reverse everything after i
        nums[i + 1:] = reversed(nums[i + 1:])