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
    bool isPalindrome(ListNode* head) {
        if(!head) return false;
        
        //FIND THE MID
        ListNode* slow, *fast;
        slow = fast = head;
        
        while(fast -> next && fast -> next -> next){
            // cout<<slow->val<<endl<<fast->val;            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = NULL, *cur, *nex;
        cur = slow->next;
        
        while(cur){
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        
        slow->next = prev;
        
        while(prev){
            if(head->val != prev->val)
                return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};