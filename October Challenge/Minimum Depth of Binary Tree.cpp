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
    void dfs(TreeNode* root,int cur){
        if(!root) return;
        if(root->left == NULL && root->right == NULL){
            ans = min(ans,cur);
            return;
        }
        dfs(root->left,cur+1);
        dfs(root->right,cur+1);
    }
public:
    int minDepth(TreeNode* root) {
        ans = INT_MAX;
        dfs(root,1);
        return ans == INT_MAX ? 0 : ans;
    }
};