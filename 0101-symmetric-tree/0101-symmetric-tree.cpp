class Solution {
public:
    bool mirror(TreeNode* left, TreeNode* right) {
        // Both nodes are NULL
        if (left == nullptr && right == nullptr)
            return true;

        // One node is NULL
        if (left == nullptr || right == nullptr)
            return false;

        // Values must be equal
        if (left->val != right->val)
            return false;

        // Compare opposite sides
        return mirror(left->left, right->right) &&
               mirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;

        return mirror(root->left, root->right);
    }
};