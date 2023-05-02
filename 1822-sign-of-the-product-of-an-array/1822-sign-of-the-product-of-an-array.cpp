class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt = 0;
        int isZero = 0;
        
        for(int i: nums)
            (i<0)? cnt++: (i == 0)? isZero = 1:0;
        
        return  isZero ? 0: (cnt & 1)? -1:1;
    }
};