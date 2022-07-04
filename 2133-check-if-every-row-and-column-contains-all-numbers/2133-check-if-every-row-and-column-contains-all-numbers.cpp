class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        vector<vector<int>> rows(m, vector<int>(n,0));
        vector<vector<int>> cols(n, vector<int>(m,0));

        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int num = matrix[i][j] - 1;
                rows[i][num] = cols[j][num] = 1;
            }
        }
        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++)
                if(!rows[i][j] || !cols[j][i])
                    return false;
        return true;
    }
};