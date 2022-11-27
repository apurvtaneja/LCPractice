class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxi = 0;
        
        for(int i : nums){
            if(i)
                maxi = max(maxi, ++count);
            else
                count = 0;
        }
        return maxi;
    }
};