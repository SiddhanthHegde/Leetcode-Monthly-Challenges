class Solution {
public:
    int findPoisonedDuration(vector<int>& a, int d) {
        if(a.empty()) return 0;
        int c = 0;
        int n = a.size();
        for(int i = 0; i < n - 1; i++){
            c += min(a[i + 1] - a[i],d);
        }
        return c + d;
    }
};