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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0)  return head;
        
        auto ptr = head;
        int n = 1;
        while(ptr->next)
            n++, ptr = ptr->next;
        
        ptr->next = head; // CREATING A CIRCULAR LINKED LIST
        ptr = ptr->next;    //POINTING PTR TO HEAD;
        k = k%n; // if k is larger than n;
        
        k = n-k;
        while(--k)
            ptr = ptr->next;
        
        cout<<ptr->val;
        head = ptr->next;
        ptr->next = NULL;
        return head;
    }
};