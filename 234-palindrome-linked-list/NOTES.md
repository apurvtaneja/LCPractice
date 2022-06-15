```
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
// cout<<slow->val;
cur = slow->next;
while(cur){
nex = cur->next;
cur->next = prev;
prev = cur;
cur = nex;
}
slow->next = prev;
fast = slow->next;
slow = head;
while(fast){
if(slow->val != fast->val)
return false;
cout<<slow->val<<endl<<fast->val;
fast = fast->next;
slow = slow->next;
}
return true;
}
```