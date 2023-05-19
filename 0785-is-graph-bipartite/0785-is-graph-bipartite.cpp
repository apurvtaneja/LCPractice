class Solution {
    bool dfs(int i, int curC, vector<vector<int>>& graph, vector<int>& color){
        color[i] = curC;
        for(int n : graph[i]){
            if(color[n] == -1){
                if (!dfs(n, 1 - curC, graph, color))
                    return false;
            } else if(color[n] == color[i]){
                return false;
            }
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i = 0; i < n; i++){
            if(color[i] == -1 && !dfs(i, 0, graph, color))
                return false;
        }
        
        return true;
    }
};
