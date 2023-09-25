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
    long SUM = 0;
    long maxP = 0;
    int totalsum(TreeNode* root){
        if(!root)
            return 0;
        
        int left = totalsum(root->left);
        
        int right = totalsum(root->right);
        
        int sum = root->val + left + right;
        
        return sum;
    }
    
    int find(TreeNode* root){
        if(!root)
            return 0;
        
        int leftsum = find(root->left);
        int rightsum = find(root->right);
        
        long S1 = root->val + leftsum + rightsum;
        
        long S2 = SUM - S1;
        
        maxP = max(maxP,(S1*S2));
        
        return S1;
        
    }
    int maxProduct(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        SUM = totalsum(root);
        
        find(root);
        
        return maxP%1000000007;
    }
};