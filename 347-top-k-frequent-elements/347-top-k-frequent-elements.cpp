class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        
        for(int i: nums)
            mp[i]++;
        
        vector<int> res;
        
        for(auto m: mp)
                pq.push({m.second, m.first});
        
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};