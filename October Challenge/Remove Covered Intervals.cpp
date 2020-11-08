class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
        sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){
           return a[0] < b[0]; 
        });
        vector<int> cur = {-1,1};
        for(auto x : intervals){
            if(x[0] > cur[0] && x[1] > cur[1]){
                cur[0] = x[0];
                count++;
            }
            cur[1] = max(cur[1],x[1]); 
        }
        return count;
    }
};