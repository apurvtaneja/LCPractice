class Solution {
    void dfs(vector<vector<char>>& board, int i, int j){
        int rows = board.size(), cols = board[0].size();
        if(i<0 || j<0 || i>=rows || j>=cols || board[i][j] == 'X' || board[i][j] == '1')
            return;
        board[i][j] = '1';
        int offset[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        for(auto [r,c]: offset)
            dfs(board, i+r, j+c);
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        
        for(int i = 0; i<rows; i++){
            if(board[i][0] == 'O')
                dfs(board, i, 0);
            if(board[i][cols - 1] == 'O')
                dfs(board, i, cols - 1);
        }
        for(int i = 1; i<cols-1; i++){
            if(board[0][i] == 'O')
                dfs(board, 0, i);
            if(board[rows-1][i] == 'O')
                dfs(board, rows-1, i);
        }
        
        for(auto& v: board){
            for(auto& c: v){
                if(c == '1')
                    c = 'O';
                else if(c == 'O')
                    c = 'X';
            }
        }
    }
};