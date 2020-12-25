class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return {};

        int n = matrix[0].size(), r = 0, c = 0;
        vector<int> result(m*n);

        for(int i = 0; i < m*n; i++) {
                result[i] = matrix[r][c];
                if ((r + c) % 2 == 0) {
                    if (c == n - 1) {
                        r++;
                    } else if (r == 0) {
                        c++;
                    } else {
                        r--;
                        c++;
                    }
                } else {
                    if (r == m - 1) {
                        c++;
                    } else if (c == 0) {
                        r++;
                    } else {
                        r++;
                        c--;
                    }
                }
            }

            return result;
    }
};
