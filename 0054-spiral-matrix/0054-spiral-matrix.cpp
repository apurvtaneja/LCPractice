class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int> ans;
        
        int n = rows*cols;
        
        int sr = 0, sc = 0;
        int er = rows-1, ec = cols-1;
        
        int i = 0;
        while(i<n){
            
            for(int j = sc; j <= ec && i<n; j++, i++)
                ans.push_back(mat[sr][j]);
            
            sr++;
            
            for(int j = sr; j<=er && i<n; j++, i++)
                ans.push_back(mat[j][ec]);
            
            ec--;
            
            for(int j = ec; j >= sc && i<n; j--, i++)
                ans.push_back(mat[er][j]);
            
            er--;
            
            for(int j = er; j >= sr && i<n; j--, i++)
                ans.push_back(mat[j][sc]);
            sc++;
            
        }
        return ans;
    }
};