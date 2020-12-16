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
bool valid(TreeNode* root, long long l, long long r){
    if(root == NULL) return true;
    if(root->val > l && root->val < r){
        return valid(root->left, l, root->val)
            && valid(root->right, root->val, r);
    } else{
        return false;
    }
}
bool isValidBST(TreeNode* root) {
    if(root == NULL) return true;
    bool l = valid(root->left, LONG_MIN, root->val);
    bool r = valid(root->right, root->val, LONG_MAX);
    return l && r;
}

};