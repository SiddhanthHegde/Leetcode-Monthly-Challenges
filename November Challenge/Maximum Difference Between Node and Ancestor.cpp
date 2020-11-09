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
    int result;
    void find(TreeNode* node, int cmin, int cmax){
        if(!node) return;
        result = max({abs(node->val - cmin), abs(node->val - cmax),result});
        cmin = min(node->val,cmin);
        cmax = max(node->val,cmax);
        find(node->left,cmin,cmax);
        find(node->right,cmin,cmax);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        result = 0;
        find(root,root->val,root->val);
        return result;
    }
};