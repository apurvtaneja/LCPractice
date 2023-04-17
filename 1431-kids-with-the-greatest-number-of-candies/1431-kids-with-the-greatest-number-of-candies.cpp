class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> result(n);
        
        int maxCandies = *max_element(candies.begin(), candies.end());
        
        for(int i = 0; i<n; i++)
            candies[i] + extraCandies >= maxCandies ? result[i] = true: result[i] = false;
        
        return result;
    }
};