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
    ListNode* middlenode(ListNode* head){
        if(head==NULL or head->next==NULL)
            return head;
        
        ListNode* slow=head,*fast=head;
        while(fast->next!=NULL and fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        if(head==NULL or head->next==NULL)
            return head;
        ListNode* prev=NULL,*curr=head,*forw=NULL;
        while(curr!=NULL){
            forw=curr->next; //backup
            curr->next=prev; //link
            prev=curr; 
            curr=forw;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head){
        if(head==NULL or head->next==NULL)
            return true;
        ListNode* midnode=middlenode(head);
        //reverse the 2nd half of the list
        ListNode* newhead=midnode->next; // taking the 1st mid
        midnode->next=NULL;  
        newhead=reverse(newhead);
        
        ListNode* c1=head,*c2=newhead; 
        bool res=true;
        while(c1!=NULL and c2!=NULL){          // only c2 is required
            if(c1->val!=c2->val){
                res=false;
                break;
            }
            c1=c1->next;
            c2=c2->next;
        }
        // making the list in the original form
        newhead=reverse(newhead);
        midnode->next=newhead;
        return res;
    }
};