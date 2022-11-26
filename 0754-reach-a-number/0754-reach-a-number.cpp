class Solution {
public:
    int minMoves(int steps, int source, int target){
        if(abs(source) > target)
            return INT_MAX;
        if(source == target)
            return steps;
            
        return min(minMoves(steps+1, source + steps + 1, target), 
                   minMoves(steps+1, source - steps - 1, target));
    }
    int reachNumber(int target) {
        // return minMoves(0, 0, abs(target));
        int k = 1, sum = 0;
        target = abs(target);
        
        while(sum<target || (sum - target)%2 == 1)
            sum += k++;
        
        return k-1;
        
        
    }
};