// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    bool dfs(int node, int prevNode, vector<int>& visited, vector<int> adj[]){
        visited[node] = 1;
        
        for(auto i: adj[node]){
            if(visited[i] == 0){
                if(dfs(i, node, visited, adj))
                    return true;
            }
            else if(i != prevNode)
                return true;
        }
        return false;
    }
    bool bfs(int i, vector<int> adj[], vector<int> &vis)
    {
        queue<pair<int, int>> q;
        q.push({i, -1});
        vis[i] = 1;
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    vis[it] = true;
                    q.push({it, node});
                }
                else if(it != parent)
                    return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        
        vector<int> visited(V,0);
        
        for(int i = 0; i<V; i++)
            if(!visited[i])
                // if(dfs(i, -1, visited, adj))
                if(bfs(i, adj, visited))
                    return true;
        
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends