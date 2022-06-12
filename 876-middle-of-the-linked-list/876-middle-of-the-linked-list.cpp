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
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr;
        int total=0;
        
        ptr = head;
        
        while(ptr){
            total++;
            ptr = ptr->next;
        }
        ptr = head;
        int i = 0;
        while(ptr){
            if(i == total/2)
                break;
            i++;
            ptr = ptr->next;
        }
        // cout<<ptr->val;
        
        return ptr;
    }
};