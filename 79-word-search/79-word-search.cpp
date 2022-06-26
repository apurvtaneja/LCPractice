class Solution {
private:
    bool dfsSearch(vector<vector<char>>& board, string word, int n, int r, int c){
        if(n == word.length())
            return true;
        int rows = board.size(), cols = board[0].size();
        if(r<0 || c<0 || r>=rows || c>=cols || word[n]!=board[r][c] || board[r][c]=='*')
            return false;
        
        char tmp = board[r][c];
        board[r][c] = '*';
        bool res =  dfsSearch(board, word, n+1, r, c + 1) ||
                    dfsSearch(board, word, n+1, r + 1, c) ||
                    dfsSearch(board, word, n+1, r, c -1)  ||
                    dfsSearch(board, word, n+1, r - 1, c);
        board[r][c] = tmp;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int rows = board.size(), cols = board[0].size();
        for(int i = 0;i<rows; i++)
            for(int j = 0; j<cols; j++)
                if(board[i][j] == word[0])
                    if(dfsSearch(board, word, 0, i, j))
                        return true;
        
        return false;
        
    }
};