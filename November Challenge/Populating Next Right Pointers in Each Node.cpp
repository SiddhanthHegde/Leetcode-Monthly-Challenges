class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        dfs(root->left, root->right, root);
        return root;
    }
    
    void dfs(Node* left, Node* right, Node* root) {
        if (!(left && right)) {
            return;
        }
        left->next = right;
        if (root->next) {
            right->next = root->next->left;
        }
        dfs(left->left, left->right, left);
        dfs(right->left, right->right, right);
    }
};