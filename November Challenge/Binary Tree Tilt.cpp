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
    int ans;
    int findsum(TreeNode* node){
        if(!node) return 0;
        int left = findsum(node->left);
        int right = findsum(node->right);
        ans += abs(left - right);
        return left + right + node->val;
    }
public:
    int findTilt(TreeNode* root) {
        ans = 0;
        findsum(root);
        return ans;
    }
};