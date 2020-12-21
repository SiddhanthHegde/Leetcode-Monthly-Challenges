class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        int n = A.size();
        if(n == 0 || n == 1) return 0;
        sort(A.begin(),A.end());
        int res = A[n - 1] - A[0];
        for(int i = 0; i < n-1; i++){
            int j = i + 1;
            int low = min(A[0] + K, A[j] - K);
            int high = max(A[n - 1] - K, A[i] + K);
            res = min(res,high - low);
        }
        return res;
    }
};
