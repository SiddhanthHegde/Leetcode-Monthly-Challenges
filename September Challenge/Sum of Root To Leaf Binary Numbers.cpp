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
    int sum = 0;
    int convdec(string x){
        int n = x.size();
        int ret = 0;
        for(int i = n - 1,j=0; i >=0; i--,j++){
            if(x[i] == '1'){
                ret += pow(2,j);
            }
        }
        return ret;
    }
    void findsum(TreeNode* node,string x){
        if(!node) return;
        if(node->left){
            findsum(node->left,x + to_string(node->left->val));
        }
        if(node->right){
            findsum(node->right,x + to_string(node->right->val));
        }
        if(node->left == NULL && node->right == NULL ){
            sum += convdec(x);
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root) return 0;
        findsum(root,to_string(root->val));
        return sum;
    }
};