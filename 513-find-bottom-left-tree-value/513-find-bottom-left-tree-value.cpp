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
    void solve(TreeNode* root,int &maxdepth,int &leftval,int depth){
        if(root==NULL)
            return;
        solve(root->left,maxdepth,leftval,depth+1);
        solve(root->right,maxdepth,leftval,depth+1);
        if(depth>maxdepth){
            maxdepth=depth;
            leftval=root->val;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        int maxdepth=0;
        int leftval=root->val;
        solve(root,maxdepth,leftval,0);
        return leftval;
    }
};