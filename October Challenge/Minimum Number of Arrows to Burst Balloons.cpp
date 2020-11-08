class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        int n = a.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        sort(a.begin(),a.end(),[](vector<int> x, vector<int> y){
           return x[1] < y[1];
        });
        int arr = 1;
        int end = a[0][1];
        for(int i = 1; i < n; i++){
            if(a[i][0] > end){
                arr++;
                end = a[i][1];
            }
        }
        
        return arr;
    }
};