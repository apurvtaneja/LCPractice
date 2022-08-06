class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i<n; i++){
            unordered_set<int> s1,s2;
            for(int j =0; j< n; j++){
                //For Row
                if(s1.find(matrix[i][j]) != s1.end())
                    return false;
                else
                    s1.insert(matrix[i][j]);
                
                //For Col
                if(s2.find(matrix[j][i]) != s2.end())
                    return false;
                else
                    s2.insert(matrix[j][i]);
            }
        }
        return true;
    }
};