class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int kCount = 0, prefSum = 0;
        unordered_map<int, int> prefSumCount;
        
        for(int i: nums){
            prefSum += i;
            if(prefSum == k)    
                kCount++;
            if(prefSumCount[prefSum - k] != 0)
                kCount += prefSumCount[prefSum - k];
            
            prefSumCount[prefSum] += 1;
        }
        return kCount;
    }
};