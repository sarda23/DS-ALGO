/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodCount=0;
    void solve(TreeNode* root,int maxv){
        if(root==NULL)
            return;
        if(root->val>=maxv)
            goodCount++;
        solve(root->left,max(root->val,maxv));
        solve(root->right,max(root->val,maxv));
        return;
    }
    int goodNodes(TreeNode* root) {
        solve(root,INT_MIN);
        return goodCount;
    }
};