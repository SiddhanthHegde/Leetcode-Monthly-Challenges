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
    unordered_map<TreeNode*,int> mp;
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
            if (mp.find(root) != mp.end()) return mp[root];
            int val = 0;
            if (root->left) val += rob(root->left->left) + rob(root->left->right);
            if (root->right) val += rob(root->right->left) + rob(root->right->right);

            mp[root] = max(root->val + val, rob(root->left) + rob(root->right));
            return mp[root];
    }
};