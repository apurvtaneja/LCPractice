class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        
        int sr = 0, er = n - 1;
        int sc = 0, ec = n - 1;
        
        int numOfEl = n*n;
        
        int i = 1;
        
        while(i <= numOfEl){
            
            for(int j = sc; j <= ec && i <= numOfEl; j++, i++)
                mat[sr][j] = i;
            
            sr++;
            
            for(int j = sr; j <= er && i <= numOfEl; j++, i++)
                mat[j][ec] = i;
            
            ec--;
            
            for(int j = ec; j >= sc && i <= numOfEl; j--, i++)
                mat[er][j] = i;
            
            er--;
            
            for(int j = er; j >= sr && i <= numOfEl; j--, i++)
                mat[j][sc] = i;
            sc++;
        }
        return mat;
        
    }
};