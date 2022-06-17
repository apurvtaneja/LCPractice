class Solution {
private:
    bool checkValid(int i, int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=n)    return false;
        return true;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> ans(rows,vector<int>(cols,-1));
        
        for(int i = 0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        
        int offset[4][2] = {{0,1},
                            {1,0},
                            {0,-1},
                            {-1,0}};
        
        while(!q.empty()){
            auto [i,j] = q.front();
            
            for(auto [ni,nj]:offset){
                ni += i;
                nj += j;
                if(checkValid(ni,nj,rows,cols) && ans[ni][nj]==-1){
                    q.push({ni,nj});
                    ans[ni][nj] = ans[i][j] + 1;
                }
            }
            q.pop();
        }
        return ans;
    }
};