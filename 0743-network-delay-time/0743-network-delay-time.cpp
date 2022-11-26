#define pii pair<int, int>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pii> adj[n];
        
        for(auto vec: times){
            int u = vec[0], v = vec[1], cost = vec[2];
            adj[u-1].push_back({v-1, cost});
        }
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        vector<bool> seen(n, false);
        
        vector<int> distance(n, INT_MAX);
        distance[k-1] = 0;
        
        pq.push({0,k-1});
        
        while(!pq.empty()){
            auto [cost, node] = pq.top();
            pq.pop();
            
            if(seen[node])    continue;
            seen[node] = true;
            
            for(auto [next, wt]: adj[node]){
                if(distance[next] > cost + wt){
                    distance[next] = cost + wt;
                    pq.push({distance[next], next});
                }
            }
        }
        int minTime = INT_MIN;
        for(int i:distance)
                minTime = max(minTime, i);
        
        return minTime==INT_MAX?-1:minTime;
    }
};