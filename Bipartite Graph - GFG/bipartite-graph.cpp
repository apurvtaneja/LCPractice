// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    bool bfs(int node, vector<int>& color, vector<int> adj[]){
        color[node] = 0;
        queue<int> q;
        
        q.push(node);
        while(!q.empty()){
            int parent = q.front();
            q.pop();
            
            for(auto it:adj[parent]){
                if(color[it]==-1){
                    color[it] = 1 - color[parent];
                    q.push(it);
                }
                else if(color[it] == color[parent])
                    return false;
            }
        }
        return true;
    }
    
    bool dfs(int node, vector<int>& color, vector<int> adj[]){
        if(color[node] == -1) color[node] = 0;
        
        for(auto it: adj[node]){
            if(color[it] == -1){
                color[it] = 1 - color[node];
                if(!dfs(it, color, adj))
	                return false;
            }
            else if(color[it] == color[node])
                return false;
        }
        return true;
        
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1);
	    for(int i = 0; i<V; i++){
	        if(color[i] == -1)
	            if(!dfs(i, color, adj))
	           // if(!bfs(i, color, adj))
	                return false;
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends