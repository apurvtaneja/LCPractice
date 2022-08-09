class Solution {
private:
    void backtrack(int n, int row, vector<vector<string>>& res, vector<string>& board){
        if(row==n){
            res.push_back(board);
            return ; 
        }
        
        for(int col = 0; col < n; col++){   //Shifting through each col
            if(!isValid(row, col, n, board))
                continue;
            
            board[row][col] = 'Q';
            
            backtrack(n, row +1, res, board);
            
            board[row][col] = '.';
        }
    }
    
    bool isValid(int row, int col, int n, vector<string>& board){
        for(int i = 0; i<n; i++)
            if(board[i][col] == 'Q')
                return false;
        
        for(int i = row-1, j = col-1; i>=0 && j>=0; i--, j--)
            if(board[i][j] == 'Q')
                return false;
        
        for(int i = row-1, j = col+1; i>=0 && j<n; i--, j++)
            if(board[i][j] == 'Q')
                return false;
        return true;        
    }
   
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(n, 0, res, board);
        return res;
    }
};