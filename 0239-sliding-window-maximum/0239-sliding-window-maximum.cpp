class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k)
            return {};
        vector<int> ans;
        
        int i = 0, j = 0;
        
        deque<int> dq;
        
        while(j<n){
            
            while(!dq.empty() && nums[dq.back()] < nums[j])
                dq.pop_back();
            
            dq.push_back(j);
            
            if(i > dq.front())
                dq.pop_front();
            
            if(j+1>=k){
                ans.push_back(nums[dq.front()]);
                i++;
            }
            j++;
        }
        return ans;
    }
};