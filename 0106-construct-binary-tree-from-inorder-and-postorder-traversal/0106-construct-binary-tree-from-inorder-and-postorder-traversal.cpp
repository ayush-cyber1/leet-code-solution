/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        int postIdx = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1, postIdx, inorderIndex);
    }

private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                     int inStart, int inEnd, int& postIdx,
                     unordered_map<int, int>& inorderIndex) {
        if (inStart > inEnd) return nullptr;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = inorderIndex[rootVal];

        root->right = build(inorder, postorder, mid + 1, inEnd, postIdx, inorderIndex);
        root->left = build(inorder, postorder, inStart, mid - 1, postIdx, inorderIndex);

        return root;
    }
};