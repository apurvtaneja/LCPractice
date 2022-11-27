class Solution {
public:
    bool inBounds(int newr, int newc, int m, int n){
        if(newr >= 0 && newr < m && newc >= 0 && newc<n)
            return true;
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0])
            return -1;
        int m = grid.size();
        int n = grid[0].size();
        queue<tuple<int,int,int>> q; // distance, row , col
        
        vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
        
        dist[0][0] = 0;
        int direction[8][2] = {{-1,0}, {-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
        //  UP, TOP RIGHT, RIGHT, BOTTOM RIGHT, 
        q.push({0,0,0});
        
        while(!q.empty()){
            auto [dis, r, c]= q.front();
            q.pop();
            
            for(auto [dr,dc] : direction){
                int newr = r + dr;
                int newc = c + dc;
                
                if(inBounds(newr, newc, m, n) && grid[newr][newc] == 0 && dis + 1 < dist[newr][newc]){
                    dist[newr][newc] = 1 + dis;
                    // if(newr == m-1 && newc == n-1)
                    //     return dis+1;
                    q.push({1+dis, newr, newc});
                }
            }
        }
        return dist[m-1][n-1] == INT_MAX? -1: (dist[m-1][n-1]+1);
    }
};