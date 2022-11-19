class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1 = -1, el2 = -1;
        int c1 = 0, c2 = 0;
        
        for(int i: nums){
            if(el1 == i)
                c1++;
            else if(el2 == i)
                c2++;
            else if(c1 == 0)
                el1 = i, c1 = 1;
            else if(c2 == 0)
                el2 = i, c2 = 1;
            else
                c1--,c2--;
        }
        c1 = 0, c2 = 0;
        vector<int> ans;
        for(int i: nums){
            if(el1 == i)
                c1++;
            else if(el2 == i)
                c2++;
        }
        int n = nums.size();
        if(c1> n/3)
            ans.push_back(el1);
        if(c2> n/3)
            ans.push_back(el2);
        return ans;
    }
};