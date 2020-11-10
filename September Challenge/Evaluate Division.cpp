class Solution {
    unordered_map<string,vector<pair<string,double>>> mp;
    double dfs(string& src,string& dst,unordered_set<string>& s){
        auto its = mp.find(src);
        auto itd = mp.find(dst);
        if(its == mp.end() || its == mp.end()) return -1.0;
        if(src == dst) return 1.0;
        s.insert(src);
        for(auto v : its->second){
            if(s.find(v.first) != s.end()){
                double ans = dfs(v.first,dst,s);
                if(ans != -1.0) return ans * v.second;
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i < (int)values.size(); i++){
            string src = eq[i][0];
            string dst = eq[i][1];
            mp[src].push_back({dst,values[i]});
            mp[dst].push_back({dst,1/values[i]});
        }
        int n = queries.size();
        vector<double> ans(n);
        unordered_set<string> s;
        for(int i = 0; i < n; i++)
            ans[i] = dfs(queries[i][0],queries[i][1],s);
        return ans;
    }
};