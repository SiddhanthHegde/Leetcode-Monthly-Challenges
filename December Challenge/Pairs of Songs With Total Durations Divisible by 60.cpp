class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> c(60);
        for(int x : time){
            c[x % 60]++;
        }
        int ans = 0;
        for(int i = 1; i < 30; i++){
            ans += c[i] * c[60 - i];
        }
        ans += ((c[0] * (c[0] - 1))/2) + ((c[30] * (c[30] - 1))/2);
        return ans;
    }
};