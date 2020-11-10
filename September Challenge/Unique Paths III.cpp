class Solution {
    int row,col;
    int dfs(vector<vector<int>>& grid, int x, int y, int zeros){
        if(x < 0 || y < 0 || x >= row || y >= col || grid[x][y] == -1) return 0;
        if(grid[x][y] == 2) return zeros == -1 ? 1 : 0;
        zeros--;
        grid[x][y] = -1;
        int total = dfs(grid,x + 1,y,zeros) +
            dfs(grid,x - 1,y,zeros) +
            dfs(grid,x,y + 1,zeros) +
            dfs(grid,x,y - 1,zeros);
        zeros++;
        grid[x][y] = 0;
        return total;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        row = grid.size(); 
        col = grid[0].size();
        int zeros = 0, sx = 0, sy = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 0) zeros++;
                if(grid[i][j] == 1){
                    sx = i;
                    sy = j;
                }
            }
        }
        return dfs(grid,sx,sy,zeros);
    }
};