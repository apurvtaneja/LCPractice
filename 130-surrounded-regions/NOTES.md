visited[i][j] = 1;
int offset[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
for(auto [r,c]: offset)
dfs(board, i+r, j+c, visited);
}
void markX(vector<vector<char>>& board, int i, int j){
int rows = board.size(), cols = board[0].size();
if(i<0 || j<0 || i>=rows || j>=cols)
return;
if(board[i][j] == 'X')
return;
board[i][j] = 'X';
int offset[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
for(auto [r,c]: offset)
markX(board, i+r, j+c);
}
public:
void solve(vector<vector<char>>& board) {
int rows = board.size();
int cols = board[0].size();
vector<vector<int>> visited(rows, vector<int>(cols, 0));
for(int i = 1; i<rows-1; i++){
for(int j = 1; j<cols-1; j++){
if(board[i][j] == 'O' && !visited[i][j]){
isTouchingBoundary = false;
dfs(board, i, j, visited);
if(!isTouchingBoundary)
markX(board, i, j);
isTouchingBoundary = true;
}
}
}
}
};
```