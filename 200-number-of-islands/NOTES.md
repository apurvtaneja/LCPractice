```
class Solution {
private:
bool isInBound(int i, int j, int row, int col){
if(i>=0 && j>=0 && i<row && j <col)
return true;
return false;
}
public:
int numIslands(vector<vector<char>>& grid) {
int islands = 0;
int row = grid.size();
int col = grid[0].size();
int offset[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
for(int i = 0; i<row; i++){
for(int j = 0; j<col; j++){
if(grid[i][j] == '0')   continue;
islands++;
grid[i][j] = '0';
queue<pair<int,int>> q;
q.push({i,j});
while(!q.empty()){
auto [ni,nj] = q.front();
q.pop();
for(auto [r,c]:offset){
r += ni;    c += nj;
if(isInBound(r, c, row, col) && grid[r][c]=='1'){
grid[r][c] = '0';
q.push({r,c});
}
}
}
}
}
return islands;
}
};
```