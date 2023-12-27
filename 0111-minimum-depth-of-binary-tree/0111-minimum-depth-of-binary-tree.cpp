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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        if(!root->left && !root->right)
            return 1;
        
        // DFS
        
        int left = root->left != NULL ? minDepth(root->left):INT_MAX;
        
        int right = root->right != NULL ? minDepth(root->right):INT_MAX;
        
        return 1 + min(left,right); 
    }
};