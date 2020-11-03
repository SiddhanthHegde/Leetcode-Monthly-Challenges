class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        char prev = '-';
        int count = 1, ans = 1;
        for(char x : s){
            if(x == prev) count++;
            else count = 1;
            ans = max(count,ans);
            prev = x;
        }
        return ans;
    }
};