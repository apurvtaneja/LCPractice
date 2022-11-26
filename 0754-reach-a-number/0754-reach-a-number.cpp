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
        int k = 0;
        int sum = 0;
        while(sum<abs(target))
            sum += ++k;
        
        return (sum - target)%2 == 0? k : k%2 == 0? k+1: k+2; 
        
        
    }
};