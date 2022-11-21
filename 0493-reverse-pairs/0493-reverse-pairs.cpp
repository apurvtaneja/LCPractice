class Solution {
public:
    int merge(vector<int>& nums, int s, int mid, int e){
        int j = mid + 1;
        int count = 0;
        for(int i = s; i<=mid; i++){
            while(j <= e && (nums[i] > (long)2 * nums[j]))
                j++;
            count += (j - (mid +1));
        }
        int n1 = mid - s + 1;
        int n2 = e - mid;
        vector<int> L(n1), R(n2);
        for(int i = 0; i<n1; i++)
            L[i] = nums[s+i];
        
        for(int i = 0; i<n2; i++)
            R[i] = nums[mid +1 +i];
        int k = s;
        int i = 0;
        j = 0;
        
        while(i < n1 && j <n2){
            if(L[i] <= R[j])
                nums[k++] = L[i++];
            else
                nums[k++] = R[j++];
        }
        while(i < n1)
            nums[k++] = L[i++];
        while(j<n2)
            nums[k++] = R[j++];
        return count;
    }
    
    int mergeSort(vector<int>& nums, int s, int e){
        if(s>=e)
            return 0;
        
        int mid = s + ((e - s)/2);
        int pairs = mergeSort(nums, s, mid);
        pairs += mergeSort(nums, mid+1, e);
        pairs += merge(nums, s, mid, e);
        return pairs;
        
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};