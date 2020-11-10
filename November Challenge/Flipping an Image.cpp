class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(auto& v : A){
            reverse(v.begin(),v.end());
            for(auto& x : v){
                if(x) x = 0;
                else x = 1;
            }
        }
        return A;
    }
};