class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
           if(a[0] == b[0]) return a[1] < b[1];
            else return a[0] < b[0];
        });
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n == 1) return intervals;
        ans.push_back(intervals[0]);
        for(int i = 1; i < (int)intervals.size(); i++){
            vector<int> k = ans.back();
            if(intervals[i][0] > k[1]) ans.push_back(intervals[i]);
            else{
                int first =  min(k[0],intervals[i][0]);
                int second = max(k[1], intervals[i][1]);
                ans.pop_back();
                ans.push_back({first, second});
            }
        }
        return ans;
    }
};