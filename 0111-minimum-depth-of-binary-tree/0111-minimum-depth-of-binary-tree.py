class Solution:
    def minDepth(self, root):
        if root is None:
            return 0

        # Leaf node
        if root.left is None and root.right is None:
            return 1

        # Only right child exists
        if root.left is None:
            return 1 + self.minDepth(root.right)

        # Only left child exists
        if root.right is None:
            return 1 + self.minDepth(root.left)

        # Both children exist
        return 1 + min(
            self.minDepth(root.left),
            self.minDepth(root.right)
        )