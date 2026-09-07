class Solution:
    def flatten(self, root):
        if root is None:
            return

        # Flatten right subtree
        self.flatten(root.right)

        # Flatten left subtree
        self.flatten(root.left)

        # Save the already flattened right subtree
        right = root.right

        # Move left subtree to the right
        root.right = root.left
        root.left = None

        # Attach old right subtree at the end
        current = root

        while current.right:
            current = current.right

        current.right = right