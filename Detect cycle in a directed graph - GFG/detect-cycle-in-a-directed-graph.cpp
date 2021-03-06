// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    bool dfs(int node, vector<int>& visit, vector<int>& dfsVisit, vector<int> adj[]){
        visit[node] = 1;
        dfsVisit[node] = 1;
        
        for(auto it: adj[node]){
            if(!visit[it]){
                if(dfs(it, visit, dfsVisit, adj))
                    return true;
            }
            else if(dfsVisit[it] == 1)
                return true;
        }
        dfsVisit[node] = 0;
        return false;
    }
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
	    
	    for(int i = 0; i<V; i++)
	        for(auto it:adj[i])
	            indegree[it]++;
	            
        queue<int> q;
        vector<int> topo;
        
	    for(int i = 0; i<V; i++)
	        if(indegree[i]==0)
	            q.push(i);
        
        int cnt=0;
	   while(!q.empty()){
	        int node = q.front();
	        q.pop();
            topo.push_back(node);
            cnt++;
	        for(auto it: adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0)
    	            q.push(it);
	       }
	   }
	   if(cnt == V) return false;
	   return true;
	   
	   
        // vector<int> visit(V+1,0), dfsVisit(V+1,0);
        // for(int i = 0; i<V; i++)
        // if(!visit[i])
        //     if(dfs(i, visit, dfsVisit, adj))
        //         return true;
        
        // return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends