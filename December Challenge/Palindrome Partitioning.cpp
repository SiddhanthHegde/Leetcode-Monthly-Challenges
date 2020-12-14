class Solution {
    vector<vector<string>> ans;
    bool isp(string& s){
        int n = s.size();
        for(int i = 0; i < n/2; i++){
            if(s[i] != s[n - i - 1]) return false;
        }
        return true;
    }
    void check(string& s, vector<string>& curr){
        int n = s.size();
        if(n == 0) ans.push_back(curr);
        for(int i = 1; i <= n; i++){
            string a = s.substr(0,i);
            string b = s.substr(i);
            if(isp(a)){
                vector<string> temp(curr.begin(), curr.end());
                temp.push_back(a);
                check(b, temp);
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> lis;
        check(s,lis);
        return ans;
    }
};