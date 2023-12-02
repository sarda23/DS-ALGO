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
    vector<vector<int>> res;
    
    void solve(TreeNode* root,int &target,vector<int>temp,int sum){
        if(!root)
            return;
        
        sum += root->val;
        temp.push_back(root->val);
        
        if(!root->left && !root->right){
            
            if(target == sum){
                res.push_back(temp);
                return;
            }
        }
        
        
        solve(root->left,target,temp,sum);
        solve(root->right,target,temp,sum);
    
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear();
        if(!root)
            return res;
        
        vector<int>temp; 
        int sum = 0;
        solve(root,targetSum,temp,sum);
        
        return res;    
    }
};