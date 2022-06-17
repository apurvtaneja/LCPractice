#define squareOfMinus( x1, x2) ( ( x1 - x2 ) *  ( x1 - x2 ))
#define addSquareOfMinus(x1, y1) (squareOfMinus( x1, 0) + squareOfMinus( y1, 0))

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,int>> pq;
        vector<vector<int>> res(k);
        
        for(int i = 0; i<n; i++){
            int dis = addSquareOfMinus(points[i][0],points[i][1]);
            pq.push({-dis,i});
        }
        while(--k>=0){
            res[k] = points[pq.top().second];  
            pq.pop();
        }
        return res;
    }
};