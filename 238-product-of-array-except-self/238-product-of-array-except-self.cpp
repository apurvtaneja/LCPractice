class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1;
        bool zero = false;
        int numZero = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i])
                totalProduct *= nums[i];
            else if(nums[i]==0){
                zero = true;
                numZero++;
            }
        }
        cout<<endl<<totalProduct;
        for(int i=0; i<nums.size(); i++){
            if(numZero>1)
                nums[i] = 0;
            else if(nums[i]==0)
                nums[i] = totalProduct;
            else{
                if(zero)
                    nums[i] = 0;
                else
                    nums[i] = totalProduct / nums[i];
            }
        }
        return nums;
    }
};

/*
[1,2,3,4]

total prod = 24

[3,9,1,5,7,8]
total prod = 7,560

[2520, 840]
0


*/