#define ll long long
#define pll pair<ll,ll>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pll> graph[n];
        int mod = 1e9+7;
        for(auto vec: roads){
            int u = vec[0], v = vec[1], t = vec[2];
            graph[u].push_back({v,t});
            graph[v].push_back({u,t});
        }
        
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        // {TIME, FROM}
        
        
        vector<ll> times(n, LONG_LONG_MAX);
        vector<ll> ways(n, 0);
        times[0] = 0;
        ways[0] = 1;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            auto [dist, prev] = pq.top();
            pq.pop();
            for(auto [next, nextTime]: graph[prev]){
                if(times[next] > dist + nextTime){
                    times[next] = dist + nextTime;
                    pq.push({times[next], next});
                    ways[next] = ways[prev];
                }
                else if(times[next] == dist + nextTime)
                    ways[next] = (ways[next] + ways[prev])%mod;
            }
        }
        
        return ways[n-1];
    }
};