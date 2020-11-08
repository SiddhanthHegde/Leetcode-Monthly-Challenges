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
    TreeNode *first, *second, *prev; 
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(first == NULL && prev != NULL && prev->val >= root->val) first = prev;
        if(first != NULL && prev != NULL && prev->val >= root->val) second = root;
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = NULL, second = NULL, prev = NULL;
        inorder(root);
        swap(first->val,second->val);
    }
};