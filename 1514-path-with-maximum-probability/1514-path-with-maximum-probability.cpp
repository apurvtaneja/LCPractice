class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> adj[n];
        
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        
        priority_queue<pair<double, int>> pq;
        
        vector<double> prob(n, 0.00);
        prob[start] = 1;
        
        pq.push({1, start});
        
        while(!pq.empty()){
            auto [p, prev] = pq.top();
            pq.pop();
            // if(prev == end)
            //     return p;
            for(auto [next, pNext]: adj[prev]){
                if(prob[next] < p * pNext){
                    prob[next] = p * pNext;
                    
                    pq.push({prob[next], next});
                }
            }
        }
        return prob[end];
    }
};