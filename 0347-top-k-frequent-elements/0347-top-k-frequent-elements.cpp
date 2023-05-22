class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        // priority_queue<pair<int, int>> pq;
        
        for(int i: nums)
            mp[i]++;
        
        vector<int> res;
        int n = nums.size();
        vector<vector<int>> bucketSort(n+1);
        
        for(auto m: mp)
            bucketSort[m.second].push_back(m.first);
        
        for(int i = n; i>=0; i--){
            for(int j = 0; j<bucketSort[i].size(); j++){
                res.push_back(bucketSort[i][j]);
                if(res.size() == k) return res;
            }
        }
        
            
            
            
//         for(auto m: mp)
//                 pq.push({m.second, m.first});
//         while(k--){
//             res.push_back(pq.top().second);
//             pq.pop();
//         }
        return res;
    }
};