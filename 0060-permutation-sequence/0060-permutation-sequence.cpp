
class Solution {
public:
    //STRIVER: https://www.youtube.com/watch?v=wT7gcXLYoao&ab_channel=takeUforward
    string getPermutation(int n, int k) {
        vector<int> arr;
        int fact = 1;
        
        for(int i = 1; i<n; i++){
            arr.push_back(i);
            fact = fact * i;
        }
        arr.push_back(n);

                
        string ans = "";
        k = k - 1;
        while(true){
            ans += to_string(arr[k/fact]);
            arr.erase(arr.begin()+ (k/fact));
            if(arr.size() == 0)
                break;
            
            k = k % fact;
            fact = fact / arr.size();
        }
        
            
        return ans;
    }
};