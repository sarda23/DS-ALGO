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
    int count=0;
    string solve(TreeNode* root){
        if(!root)
            return "ok";
        string lft=solve(root->left);
        string rgt=solve(root->right);
        
        if(lft=="want" or rgt=="want"){
            count++;
            return "provide";
        }
        if(lft=="provide" or rgt=="provide")
            return "ok";
        else
            return "want";
    }
    int minCameraCover(TreeNode* root) {
        if(solve(root)=="want")
            count++;
        
        return count;
    }
};