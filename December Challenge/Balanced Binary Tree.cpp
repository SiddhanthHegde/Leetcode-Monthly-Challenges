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
    int findheight(TreeNode* node){
        if(!node) return 0;
        int l = findheight(node->left);
        int r = findheight(node->right);
        if(l == -1 || r == -1 || abs(l - r) > 1) return -1;
        return max(l,r) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return findheight(root) != -1;
    }
};
