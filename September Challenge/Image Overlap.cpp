class Solution {
    int overlap(int row,int col,vector<vector<int>>& A, vector<vector<int>>& B){
        int n = A.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i + row < 0 || i + row >= n || j + col < 0 || j + col >= n)
                    continue;
                if(A[i][j] + B[i + row][j + col] == 2)
                    ans++;
            }
        }
        return ans;
    }
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int ans = -1;
        for(int i = -n + 1; i < n; i++){
            for(int j = -n + 1; j < n; j++){
                ans = max(ans,overlap(i,j,A,B));
            }
        }
        return ans;
    }
};