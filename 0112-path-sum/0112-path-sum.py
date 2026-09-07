class Solution:
    def hasPathSum(self, root, targetSum):
        if root is None:
            return False

        # Subtract current node's value
        targetSum -= root.val

        # Check if we reached a leaf
        if root.left is None and root.right is None:
            return targetSum == 0

        # Check either subtree
        return (self.hasPathSum(root.left, targetSum) or
                self.hasPathSum(root.right, targetSum))