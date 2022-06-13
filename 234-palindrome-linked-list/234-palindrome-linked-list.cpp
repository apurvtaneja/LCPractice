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
    ListNode* reverse(ListNode *node) {
		ListNode* prev = NULL, *nxt, *curr = node;
		while(curr) {
			nxt = curr -> next;
			curr -> next = prev;
			prev = curr;
			curr = nxt;
		}
		return prev;
	}
	bool isPalindrome(ListNode* head) {
		ListNode *slow = head, *fast = head;
		// Step 1 
		while(fast -> next && fast -> next -> next) {
			slow = slow -> next;
			fast = fast -> next -> next;
		}
		// Step 2 
		slow -> next = reverse(slow -> next);
		fast = slow -> next;
		slow = head;
		// Step 3
		while(fast) {
			if(slow -> val != fast -> val)
				return false;
			slow = slow -> next;
			fast = fast -> next;
		}
		return true;
	}
};