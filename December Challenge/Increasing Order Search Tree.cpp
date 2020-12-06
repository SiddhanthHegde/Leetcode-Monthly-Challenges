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
    TreeNode* dummy, *next;
    void inorder(TreeNode* root){
        if(root){
            inorder(root->left);
            next->right = new TreeNode(root->val);
            next = next->right;
            inorder(root->right);
        }
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        dummy = new TreeNode();
        next = dummy;
        inorder(root);
        return dummy->right;
    }
};