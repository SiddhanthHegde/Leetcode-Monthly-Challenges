class Solution {
    
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int cnt = 0;
        int n = A.size();
        unordered_map<int,int> mp;
        for(int x : A){
            for(int y : B){
                mp[x + y]++;
            }
        }
        for(int x : C){
            for(int y : D){
                auto it = mp.find(-(x+y));
                if(it != mp.end()) cnt += it->second;
            }
        }
        return cnt;
        
        
    }
};