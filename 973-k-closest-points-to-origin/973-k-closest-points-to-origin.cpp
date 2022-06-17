#define minus( x1, x2 ) ( x1 - x2 )
#define squareOfMinus( x1, x2) ( minus(x1,x2) *  minus(x1,x2))
#define squareOfMinus( x1, x2) ( minus(x1,x2) *  minus(x1,x2))
#define addSquareOfMinus(x1, x2, y1, y2) (squareOfMinus( x1, x2) + squareOfMinus( y1, y2))

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        multimap<float,int> mp;
        vector<vector<int>> res;
        
        for(int i = 0; i<n; i++){
            float distance = addSquareOfMinus(points[i][0],0,points[i][1],0);
            mp.insert(make_pair(distance,i));
        }
        int j=0;
        for(auto m:mp){
            if(j>=k)    break;
            res.push_back(points[m.second]);
            j++;
        }
        return res;
    }
};