class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int prevEnd = intervals[0][1];
        int n = intervals.size();
        
        
        for(int i = 1; i<n; i++){
            int curStart = intervals[i][0], curEnd = intervals[i][1];
            if(curStart >= prevEnd)
                prevEnd = curEnd;
            else
                count++, prevEnd = min(prevEnd,curEnd);
        }
        return count;
    }
};