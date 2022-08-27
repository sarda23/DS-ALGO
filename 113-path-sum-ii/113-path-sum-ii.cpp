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
    vector<vector<int>>res;
    vector<int>temp;
    void solve(TreeNode* root,int sum){
        if(root==NULL)
            return;
        temp.push_back(root->val);
        if(root->left==NULL and root->right==NULL and sum==root->val) 
            res.push_back(temp);
        solve(root->left,sum-root->val);
        solve(root->right,sum-root->val);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum){
        
        solve(root,targetSum);
        return res;
    }
    
};