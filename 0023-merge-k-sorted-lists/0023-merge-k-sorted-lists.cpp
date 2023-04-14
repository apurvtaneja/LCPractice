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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0)
            return NULL;
        
        return mergeSort(lists, 0, n - 1);
    }
    
    ListNode* mergeSort(vector<ListNode*>& lists, int start, int end){
        if(start == end)
            return lists[start];
        if(start + 1 == end)
            return merge(lists[start], lists[end]);
        
        int mid = start + ((end - start) / 2);
        ListNode* left = mergeSort(lists, start, mid);
        ListNode* right = mergeSort(lists, mid+1, end);
        
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode *ptr, *temp;
        temp = new ListNode();
        ptr = temp;

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

        return temp->next;
    }
};