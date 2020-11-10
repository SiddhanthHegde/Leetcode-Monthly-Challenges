class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int dp[1001] = {0};
        for(auto t : trips){
            dp[t[1]] += t[0];
            dp[t[2]] -= t[0];
        }
        for(int x : dp){
            capacity -= x;
            if(capacity < 0) return false;
        }
        return true;
    }
};