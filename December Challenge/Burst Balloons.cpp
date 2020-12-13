class Solution {
public:
    int maxCoins(vector<int>& A) {
        const int n = A.size();
        if(n == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for(int L = n - 1; L >= 0; L--){
            for(int R = L; R < n; R++){
                for(int i = L; i <= R; i++){
                    dp[L][R] = max(dp[L][R],
                                  A[i] * (L ? A[L - 1] : 1) * (R == n - 1 ? 1 : A[R + 1])
                                  + (L <= i - 1 ? dp[L][i - 1] : 0) + (i + 1 <= R ? dp[i + 1][R] : 0));
                }
            }
        }
        return dp[0][n - 1];
    }
};