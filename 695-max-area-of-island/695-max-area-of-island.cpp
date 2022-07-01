class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c){
        int rows = grid.size();
        int cols = grid[0].size();                                                                                                       
        if(r<0 || c<0 || r>=rows || c>=cols || grid[r][c] != 1)
            return 0;
        
        grid[r][c] = -1;
        
        int offset[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int res = 0;
        for(auto [i,j]:offset)
            res += dfs(grid,r+i,c+j);
        return res + 1;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = INT_MIN;
        
        for(int i = 0; i<rows;i++){
            for(int j = 0; j<cols;j++){
                if(grid[i][j] == 1)
                    maxArea = max(maxArea, dfs(grid, i, j));            
            }
        }
        return (maxArea==INT_MIN)?0:maxArea;
    }
};