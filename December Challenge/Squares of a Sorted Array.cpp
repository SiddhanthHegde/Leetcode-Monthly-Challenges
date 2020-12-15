class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int l = 0, r = A.size()-1;
        vector<int> result;
        while(l <= r){
            if(abs(A[l]) < abs(A[r])){
                result.push_back(A[r] * A[r]);
                r--;
            }else{
                result.push_back(A[l] * A[l]);
                l++;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};