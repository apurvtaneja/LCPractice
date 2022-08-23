class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = INT_MAX;
        
        for(int& i: nums)
            minNum = min(minNum,i);
        
        int noOfMoves = 0;
        for(int& i: nums)
            noOfMoves += i - minNum;
        
        return noOfMoves;
    }
};