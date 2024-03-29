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
    //pepcoding
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode* dummy=new ListNode(INT_MIN);
        ListNode* itr=dummy,*curr=head;
        while(curr!=NULL){
            while(curr!=NULL and itr->val==curr->val){
                curr=curr->next;
            }
            itr->next=curr;
            itr=itr->next;
            if(curr!=NULL)
                curr=curr->next;
        }
        return dummy->next;
            
    }
};