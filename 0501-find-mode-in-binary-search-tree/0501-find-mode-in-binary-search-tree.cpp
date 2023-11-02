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
    int currN=0,currF = 0,maxF = 0;
    vector<int>res;
    
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        dfs(root->left);
        
        if(root->val == currN){
            currF++;
        }else{
            currN = root->val;
            currF=1;
        }
        if(currF > maxF){
            res = {};
            maxF = currF;
        }
        if(currF == maxF){
            res.push_back(root->val);
        }
        dfs(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        
        return res;
    }
};