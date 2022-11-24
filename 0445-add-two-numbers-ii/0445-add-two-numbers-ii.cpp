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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> n1;
        stack<int> n2;
        
        while(l1){
            n1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            n2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* newHead = new ListNode();
        auto ptr = newHead;
        int c = 0;
        while(!n1.empty() || !n2.empty() || c){
            int sum =0;
            if(!n1.empty()){
                sum += n1.top();
                n1.pop();
            }
            if(!n2.empty()){
                sum += n2.top();
                n2.pop();
            }
            sum += c;
            c = sum / 10;
            ListNode* node = new ListNode(sum%10);
            ptr->next = node;
            ptr = ptr->next;
        }
        ListNode* prev= NULL;
        auto cur = newHead->next;
        auto nex = cur;
        while(cur){
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        return prev;
    }
};