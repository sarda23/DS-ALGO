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
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next)
            return head;
        
        ListNode* prev = NULL, *curr = head, *nextnode;
        
        while(curr){
            nextnode = curr->next;
            
            curr->next = prev;
            
            prev = curr;
            
            curr = nextnode;
        }
        
        return prev;
    }
};