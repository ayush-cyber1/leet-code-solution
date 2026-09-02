class Solution {
public:
    bool validate(TreeNode* root, long long low, long long high) {
        if (root == nullptr)
            return true;

        // Node must be strictly inside the valid range
        if (root->val <= low || root->val >= high)
            return false;

        // Left subtree: values must be smaller
        // Right subtree: values must be greater
        return validate(root->left, low, root->val) &&
               validate(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};