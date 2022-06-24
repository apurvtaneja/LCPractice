class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int prev1 = cost[0], prev2 = cost[1];
        int n = cost.size();
            
        for(int i = 2; i<n; i++){
            int cur = min(prev1, prev2) + cost[i];
            prev1 = prev2; 
            prev2 = cur;
        }
        
        return min(prev1,prev2);
    }
};