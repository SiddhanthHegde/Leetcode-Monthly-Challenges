class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxv = 0, minv = INT_MAX;
        for(int x : prices){
            minv = min(minv,x);
            maxv = max(maxv,x - minv);
        }
        return maxv;
    }
};