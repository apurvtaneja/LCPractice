class Solution {
public:
    vector<vector<int>> res;
    vector<int> v;
    void dfs(vector<vector<int>>& graph, int node, int target){
        
        v.push_back(node);

        if(node == target)
            res.push_back(v);
            
        for(auto &adjNodes: graph[node])
            dfs(graph, adjNodes, target);
        
        v.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0, graph.size()-1);
        return res;
    }
};