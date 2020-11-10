class Solution {
    unordered_map<string,bool> mp;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> k(wordDict.begin(),wordDict.end());
        if(mp.find(s) != mp.end()) return mp[s];
        if(k.find(s) != k.end()){
            mp[s] = true;
            return true;
        }
        for(int i = 0; i < n; i++){
            if(k.find(s.substr(0,i)) != k.end() && wordBreak(s.substr(i),wordDict)){
                mp[s] = true;
                return true;
            }
        }
        mp[s] = false;
        return false;
    }
};