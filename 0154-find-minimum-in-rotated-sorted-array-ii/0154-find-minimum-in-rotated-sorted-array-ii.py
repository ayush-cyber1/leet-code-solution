class Solution:
    def findMin(self, nums):
        left = 0
        right = len(nums) - 1

        while left < right:
            mid = left + (right - left) // 2

            if nums[mid] > nums[right]:
                # Minimum is on the right
                left = mid + 1

            elif nums[mid] < nums[right]:
                # Minimum is at mid or on the left
                right = mid

            else:
                # Cannot determine which side contains minimum
                right -= 1

        return nums[left]