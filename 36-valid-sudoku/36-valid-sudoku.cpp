class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int squares[9][9] = {0};

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(board[i][j] == '.')  continue;
                
                int num = board[i][j] - '0' - 1;
                // int si = i/3, sj = j/3;
                int k = i / 3 * 3 + j / 3;
                if(rows[i][num] || cols[j][num] || squares[k][num])
                    return false;
                
                rows[i][num] = cols[j][num] = squares[k][num] = 1;
            }
        }
        return true;
        
    }
};