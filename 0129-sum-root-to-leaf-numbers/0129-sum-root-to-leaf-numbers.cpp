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
    int ans = 0;
    
    void solve(TreeNode* root,int sum){
        if(!root)
            return;
        
        sum = 10*(sum) + root->val;
        
        if(!root->left && !root->right)
        {
            ans += sum;
        }
        
        solve(root->left,sum);
        solve(root->right,sum);
        
    }
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        
        solve(root,0);
        return ans;
    }
};