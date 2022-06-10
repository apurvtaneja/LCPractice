class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        int idx1, idx2;
        for(idx1 = n-2; idx1 >= 0; idx1--)
            if(a[idx1]<a[idx1+1])
                break;
        
        if(idx1 < 0)
            reverse(a.begin(), a.end());
        else{    
            
            for(idx2 = n-1; idx2 >= 0; idx2--)
                if(a[idx2]>a[idx1])
                    break;

            swap(a[idx1],a[idx2]);

            reverse(a.begin()+idx1+1, a.end());
        }
    }
};