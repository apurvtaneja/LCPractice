// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; i++) fast = fast->next;
        if (!fast) return head->next;
        while (fast->next) fast = fast->next, slow = slow->next;
        slow->next = slow->next->next;
        return head;
    }
};



// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if(!head)
//             return NULL;
//         if(n == 0)
//             return head;
//         auto ptr = head;
//         int len = 0;
//         while(ptr)
//             len++, ptr = ptr->next;
        
//         if(len == 1 && n == 1)
//             return NULL;
//         if(len - n == 0){
//             head = head->next;
//             return head;
//         }
        
//         ListNode *prev = head;
        
//         ptr = head;
        
//         int i = 0;
//         while(ptr){
//             if(i == (len - n)){
//                 prev->next = ptr->next;
//                 break;
//             }
//             prev = ptr;
//             i++;
//             ptr = ptr->next;
//         }
//         return head;
//     }
// };