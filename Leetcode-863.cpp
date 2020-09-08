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
    bool rootTonodepath(TreeNode*root, int target, vector<TreeNode*>&path) {
        if (root == NULL) return false;
        if (root->val == target) {
            path.push_back(root);
            return true;
        }
        bool res = rootTonodepath(root->left, target, path) || rootTonodepath(root->right, target, path);
        if (res) path.push_back(root);
        return res;
    }

    void kdown(TreeNode*node, int level, TreeNode*blocknode, vector<int>&ans) {
        if (node == NULL || node == blocknode) return;
        if (level == 0) {
            ans.push_back(node->val);
            return ;
        }
        kdown(node->left, level - 1, blocknode, ans);
        kdown(node->right, level - 1, blocknode, ans);
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<TreeNode*> path;
        rootTonodepath(root, target->val, path);
        TreeNode* blocknode = NULL;
        vector<int> ans;
        for (int i = 0; i < path.size(); i++) {
            kdown(path[i], K - i, blocknode, ans);
            blocknode = path[i];
        }
        return ans;
    }
};
