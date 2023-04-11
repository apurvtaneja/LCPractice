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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        auto head1 = list1;
        auto head2 = list2;
        ListNode *ptr, *dummy;
        dummy = new ListNode();
        ptr = dummy;
        while(head1 && head2){
            if(head1->val < head2->val){
                ptr->next = head1;
                head1 = head1->next;
            }
            else{
                ptr->next = head2;
                head2 = head2->next;
            }
            ptr = ptr->next;
        }
        if(head1)
            ptr->next = head1;
        if(head2)
            ptr->next = head2;

        return dummy->next;
    }
};