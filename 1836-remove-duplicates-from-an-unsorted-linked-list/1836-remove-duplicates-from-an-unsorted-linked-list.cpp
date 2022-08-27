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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode* temp=head;
        unordered_map<int,int>mp;
        for(auto p=head;p!=NULL;p=p->next){
            mp[p->val]++;
        }
        ListNode* dummy=new ListNode();
        ListNode* tail=dummy;
        for(auto curr=head;curr!=NULL;curr=curr->next){
            if(mp[curr->val]>1)
                continue;
            tail->next=curr;
            tail=tail->next;
        }
        tail->next=NULL;
        return dummy->next;
    }
};