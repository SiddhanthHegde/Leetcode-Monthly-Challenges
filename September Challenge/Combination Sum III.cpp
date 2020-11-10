class Solution {
    vector<vector<int>> ans;
    void f(int k,int n,int start,vector<int>& t){
        if(n == 0 && k == t.size()){
            ans.push_back(t);
            return;
        }
        if(n < 0) return;
        for(int i = start; i <= 9; i++){
            t.push_back(i);
            f(k,n - i,i+1,t);
            t.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> t;
        f(k,n,1,t);
        return ans;
    }
};