class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<bool> incomingEdge(n, false);
        
        for(auto &v: edges)
            incomingEdge[v[1]] = true;
        
        for(int i = 0; i< n; i++)
            if(!incomingEdge[i])
                ans.push_back(i);
        
        return ans;
    }
};