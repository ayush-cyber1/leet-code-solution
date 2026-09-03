class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both are NULL
        if (p == nullptr && q == nullptr)
            return true;

        // One is NULL, the other is not
        if (p == nullptr || q == nullptr)
            return false;

        // Values are different
        if (p->val != q->val)
            return false;

        // Check left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};