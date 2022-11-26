#define tiii tuple<int, int, int>
#define pii pair<int, int>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pii> adj[n];
        for(auto vec: flights){
            int u = vec[0], v = vec[1], cost = vec[2];
            adj[u].push_back({v,cost});
        }
        
        priority_queue<tiii,vector<tiii>, greater<tiii>> pq;
        
        vector<int> prices(n+1, INT_MAX);
        vector<int> stops(n+1, INT_MAX);
            
        prices[src] = 0;
        stops[src] = 0;
        
        pq.push({0, src, 0});
        
        while(!pq.empty()){
            auto [cost, node, kSteps] = pq.top();
            pq.pop();
            
            if(node == dst)   return cost;
            if(kSteps == k+1)   continue;
            
            for(auto& [next, wt]: adj[node]){
                if(cost + wt < prices[next] || kSteps + 1 < stops[next]){
                    prices[next] = cost + wt;
                    stops[next] = kSteps + 1;
                    pq.push({prices[next], next, stops[next]});
                }
            }
        }
        return -1;
    }
};