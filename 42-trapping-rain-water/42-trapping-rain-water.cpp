class Solution {
public:
    int trap(vector<int>& h) {
        //the trapped water will be min(maxLeft, maxRight) - h[i]
        
        //calculate maxLeft and maxRight in an array for all places
        
        vector<int> maxLeft(h.size(), 0);
        
        int maxL = INT_MIN;
        maxLeft[0] = 0;
        for(int i = 1; i < h.size(); i++){
            maxLeft[i] = max(h[i-1], maxLeft[i-1]);
        }
        
        //0,1,0,2,1,0,1,3,2,1,2,1
        
        //maxLeft
        //0,0,1,1,2,2,2,2,3,3,3,3
        
        vector<int> maxRight(h.size(), 0);
        
        int maxR = INT_MIN;
        maxRight[h.size()-1] = 0;
        for(int i = h.size()-2; i >= 0; i--){
            maxRight[i] = max(h[i+1], maxRight[i+1]);
        }
        //0,1,0,2,1,0,1,3,2,1,2,1
        
        //maxRight
        //2,1,0
        
        
        int waterTrapped = 0;
        
        for(int i = 0; i<h.size(); i++){
            int x = min(maxLeft[i], maxRight[i]) - h[i];
            if(x>0)
                waterTrapped += x;
        }
        return waterTrapped;
    }
};