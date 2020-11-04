class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0) return {};
        if(n == 1) return {0};
        if(n == 2) return {0,1};
        unordered_map<int,vector<int>> mp;
        vector<int> deg(n);
        for(int i = 0; i < (int)edges.size(); i++){
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
            deg[edges[i][0]]++;
            deg[edges[i][1]]++;
        }
        queue<int> q;
        for(int i  = 0; i < n; i++){
            if(deg[i] == 1) q.push(i);
        }
        while(n > 2){
            int qs = q.size();
            n -= qs;
            while(qs--){
                int f = q.front();
                q.pop();
                vector<int> v = mp[f];
                for(int x : v){
                    deg[x]--;
                    if(deg[x] == 1)
                        q.push(x);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};