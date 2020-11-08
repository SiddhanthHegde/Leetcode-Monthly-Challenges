/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*,Node*> mp;
    Node* dfs(Node* node){
        if(node == NULL) return NULL;
        auto it = mp.find(node);
        if(it != mp.end()) return it->second;
        Node* root = new Node(node->val);
        mp[node] = root;
        for(auto ng : node->neighbors){
            root->neighbors.push_back(dfs(ng));
        }
        return root;
    }
public:
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};