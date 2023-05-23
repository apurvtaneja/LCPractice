class KthLargest {
private:
    priority_queue<int> pq;
    int k;
public:
    KthLargest(int _k, vector<int>& nums) {
        for(int i: nums)
            pq.push(-i);
        k = _k;
    }
    
    int add(int val) {
        pq.push(-val);
        
        while(pq.size() > k)
            pq.pop();
        
        
        return -pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */