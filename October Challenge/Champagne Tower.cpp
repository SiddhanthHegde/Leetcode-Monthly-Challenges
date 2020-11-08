class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double M[101][101] = {0};
        M[0][0] = poured;
        for(int i = 0; i < query_row; i++){
            for(int j = 0; j <= i; j++){
                double of = (M[i][j] - 1.0) / 2.0;
                if(of > 0){
                    M[i + 1][j] += of;
                    M[i+1][j+1] += of;
                }
            }
        }
        return min(1.0,M[query_row][query_glass]);
    }
};