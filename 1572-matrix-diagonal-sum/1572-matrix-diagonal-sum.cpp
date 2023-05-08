class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        int sum = 0;
        
        for(int i = 0, j = 0; i<rows, j< cols; i++, j++)
            sum += mat[i][j];

        for(int i = 0, j = cols - 1; i<rows, j>=0; i++, j--){
            if(i == (rows / 2) && j == (cols / 2))
                continue;
            sum += mat[i][j];
        }
        
        return sum;
    }
};