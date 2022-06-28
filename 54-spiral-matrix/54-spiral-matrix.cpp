class Solution {
private:
    bool isInside(int i, int j, int row, int col){
        if(i>=0 and j>=0 and i<row and j<col)
            return true;
        return false;
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int row = mat.size();
        int col = mat[0].size();
        const int totEl = row * col;
        
        int startRow = 0;
        int startCol = 0;
        int endRow = row-1;
        int endCol = col-1;
        int cnt = 0;
        
        while(cnt < totEl){
            
            for(int i = startCol; i <= endCol && cnt < totEl; i++, cnt++)
                res.push_back(mat[startRow][i]);
            
            startRow++;
            for(int i = startRow; i <= endRow && cnt < totEl; i++, cnt++)
                res.push_back(mat[i][endCol]);
            endCol--;
            for(int i = endCol; i >= startCol && cnt < totEl; i--, cnt++)
                res.push_back(mat[endRow][i]);
            endRow--;
            for(int i = endRow; i >= startRow && cnt < totEl; i--, cnt++)
                res.push_back(mat[i][startCol]);
            startCol++;
        }
        return res;
    }
};