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
    // pepcoding 
    // also solve 445
    ListNode* reverse(ListNode* head){
        if(head==NULL or head->next==NULL)
            return head;
        
        ListNode* prev=NULL,*forw=NULL,*curr=head;
        while(curr!=NULL){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL or l2==NULL)
            return l1!=NULL?l1:l2;
        ListNode* c1=l1,*c2=l2;
        //ListNode* c1=reverse(l1);
        //ListNode* c2=reverse(l2);
        
        ListNode* dummy=new ListNode(-1);
        ListNode* itr=dummy;
        int carry=0;
        while(c1!=NULL or c2!=NULL or carry!=0){
            int sum=carry+(c1!=NULL?c1->val:0)+(c2!=NULL?c2->val:0);
            
            int lastdigit=sum%10;
            carry=sum/10;
            itr->next=new ListNode(lastdigit);
            itr=itr->next;
            if(c1!=NULL)
                c1=c1->next;
            if(c2!=NULL)
                c2=c2->next;
        }
        return dummy->next;
    }
};