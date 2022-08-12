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
    bool solve(TreeNode* root,long long mn,long long mx){
        if(root==NULL)
            return true;
        if(root->val<=mn or root->val>=mx)
            return false;
        return solve(root->left,mn,root->val) and solve(root->right,root->val,mx);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        return solve(root,LONG_MIN,LONG_MAX);
    }
};