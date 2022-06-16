class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size();
        vector<vector<int>> res;
        //when the intervals is empty
        if(n<=0){
            res.push_back(newInterval);
            return res;
        }
        for(int i = 0; i<n; i++){
            //When the new or updated interval is appended to the front
            //No Merge
            if(newInterval[1] < intervals[i][0]){
                res.push_back(newInterval);
                for(int j = i; j<n; j++)    res.push_back(intervals[j]);
                return res;
            }
            //When the new or updated interval is appended to the back
            //No Merge
            else if(newInterval[0]>intervals[i][1]){
                res.push_back(intervals[i]);
                if(i+1>=n) 
                    res.push_back(newInterval);
            }
            //Merge Condition
            else{
                newInterval[0] = min(newInterval[0],intervals[i][0]);
                newInterval[1] = max(newInterval[1],intervals[i][1]);
                if(i+1>=n)
                    res.push_back(newInterval);
            }
        }
        return res;
    }
};