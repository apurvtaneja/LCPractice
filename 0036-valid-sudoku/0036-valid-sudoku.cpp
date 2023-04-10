class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int square[3][3][9] = {0};
            
        for(int i = 0; i<9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.')
                    continue;
                int num = int(board[i][j] - '0') - 1;
                if(row[i][num] != 0 || col[j][num] !=0 || square[i/3][j/3][num] !=0)
                    return false;
                else
                    row[i][num] =1, col[j][num] = 1, square[i/3][j/3][num] = 1;
            }
        }
        return true;
    }
};