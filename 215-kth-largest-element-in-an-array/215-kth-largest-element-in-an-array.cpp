class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(int i:nums){
            pq.push(-1 * i);
            if(pq.size()>k)
                pq.pop();
        }
        return -1 * pq.top();
        
    }
};