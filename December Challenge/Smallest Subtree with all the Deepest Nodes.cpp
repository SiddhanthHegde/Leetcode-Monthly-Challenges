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
    int maxdepth;
    TreeNode* res;
    int postorder(TreeNode* root, int depth){
        if(!root) return depth;
        int left = postorder(root->left,depth+1);
        int right = postorder(root->right,depth+1);
        if(left == right) {
            maxdepth = max(maxdepth, left);
            if(maxdepth == left) res = root;
        }
        return max(left,right);
        
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        res = NULL;
        maxdepth = -1;
        postorder(root,0);
        return res;
        
    }
};