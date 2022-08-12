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
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        temp=head;
        vector<int>nums;
        
        while(temp){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        reverse(nums.begin(),nums.end());
        int i=0;
        while(n--){
            temp->val=nums[i++];
            temp=temp->next;
        }
        return head;
    }
};