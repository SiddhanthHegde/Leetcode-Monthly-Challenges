class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0) return false;
        int col = matrix[0].size();
        if(col == 0) return false;
        bool f = false;
        int low = 0, high = row - 1;
        int r = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[mid][0] == target) return true;
            if(matrix[mid][0] < target){
                r = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        if(r == -1) return false;
        low = 0, high = col - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(matrix[r][mid] == target) return true;
            if(target > matrix[r][mid]) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};