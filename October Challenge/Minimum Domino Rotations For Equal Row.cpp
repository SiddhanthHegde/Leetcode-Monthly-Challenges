class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int a[7] = {0}, b[7] = {0};
        int same = 0;
        int n = A.size();
        for(int i = 0; i < n; i++){
            a[A[i]]++;
            b[B[i]]++;
            if(A[i] == B[i]) same++;
        }
        for(int i = 1; i < 7; i++){
            if(a[i] + b[i] - same == n) return n - max(a[i],b[i]);
        }
        return -1;
    }
};