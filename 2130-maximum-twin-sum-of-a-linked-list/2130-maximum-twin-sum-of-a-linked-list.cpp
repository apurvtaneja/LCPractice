/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {

        vector<int> arr;
        // cout<<'test';
        auto ptr = head;
        while(ptr){
            arr.push_back(ptr->val);
            ptr = ptr->next;
        }
        

        int sum = 0;
        int maxSum = 0;
        int n = arr.size();
        
        for(int i = (n/2) - 1; i<n; i++){
            sum = arr[i] + arr[n-1-i];
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};