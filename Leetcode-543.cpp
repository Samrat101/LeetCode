/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeNode*root) {
        if (root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);

        int ld = diameterOfBinaryTree(root->left);
        int rd = diameterOfBinaryTree(root->right);

        return max(lh + rh, max(ld, rd));
    }
};
