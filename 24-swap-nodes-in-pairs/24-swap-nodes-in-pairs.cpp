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
    ListNode* swapPairs(ListNode* head) {
        int n = 2;
        ListNode* prev = NULL, *cur = head, *nex;
        
        while(cur && n--){
            nex = cur->next;
            cur->next = prev; 
            prev = cur;
            cur = nex;
        }
        
        if(cur)
            head->next = swapPairs(cur);
        
        return prev;
    }
};