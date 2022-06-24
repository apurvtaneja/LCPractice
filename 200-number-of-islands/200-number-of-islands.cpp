class Solution {
private:
    void dfsDeleteIslands(vector<vector<char>>& grid, int i, int j){
        int row = grid.size(), col = grid[0].size();
        if(i<0 || j<0 || i>=row || j >= col || grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        
        int offset[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        for(auto [r,c]:offset)
            dfsDeleteIslands(grid, i+r, j+c);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == '0')   continue;
                
                islands++;
                dfsDeleteIslands(grid,i,j);
            }
        }
        return islands;
    }
};