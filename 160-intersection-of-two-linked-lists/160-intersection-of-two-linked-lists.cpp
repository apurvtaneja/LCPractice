/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto A = headA;
        auto B = headB;
        
        while(A != B){
            A = A ? A->next : headB;
            B = B ? B->next : headA;
        }
        return A;
    }
};