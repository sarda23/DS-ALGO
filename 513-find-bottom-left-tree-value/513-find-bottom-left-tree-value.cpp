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
    void solve(TreeNode* root,int &maxdepth,int &ans,int depth){
        if(root==NULL)
            return ;
        solve(root->left,maxdepth,ans,depth+1);
        solve(root->right,maxdepth,ans,depth+1);
        if(maxdepth<depth){
            maxdepth=depth;
            ans=root->val;
        }
    }
    int findBottomLeftValue(TreeNode* root){
        
        int ans=root->val,maxdepth=0;
        solve(root,maxdepth,ans,0);
        return ans;
    }
};