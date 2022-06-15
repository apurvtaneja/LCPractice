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
        
        vector<int> a,b;
        fast = slow->next;
        slow = head; 
        while(fast){
            a.push_back(slow->val);
            b.push_back(fast->val);
            slow = slow->next;
            fast = fast->next;
        }
        reverse(b.begin(),b.end());
        for(auto i:a)   cout<<i<<endl;
        cout<<endl;
        for(auto i:b)   cout<<i<<endl;

        return a == b;
    }
};