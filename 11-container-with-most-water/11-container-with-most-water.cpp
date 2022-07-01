class Solution {
public:
    int maxArea(vector<int>& h) {
        int l = 0;
        int b = 0;
        int maxArea = 0;
        
        int i = 0, j = h.size() - 1;
        while(i<j){
            l = j - i;
            b = min(h[i], h[j]);
            maxArea = max(maxArea, l*b);
            if(h[i] < h[j])   i++;
            else j--;
        }
        return maxArea;
    }
};