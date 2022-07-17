class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int s = 0, e = m * n - 1;
        
        while(s<=e){
            int mid = s + (e - s)/ 2;
            int midEl = matrix[mid/n][mid%n];
            /*
            (mid/n) will give the row value because we will be ble to find say mid
            is 7 and no. of cols are 4. so how many times 4 are laid out so we can get 7
            1   3   5   7   10  11  16  20  23  30  34  60
                                        7th
            1   3   5   7  
            10  11  16  20
            23  30  34  60
            so 7th element is 20 and 7 / 4 = 1
            */
            /*
            (mid%cols) will simply give us in which colum the element is located.
            like any number % 4. will result in answer between 0 and 3. so 7 % 4 = 3
            */
            if(midEl == target)
                return true;
            if(target < midEl)
                e = mid - 1;
            else
                s = mid +1;
        }
        return false;
    }
};