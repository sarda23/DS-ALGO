
class Solution {
public:
    vector<int>res;
    
    void dfs(TreeNode* root,int d){
        if(root == NULL)
            return;
        
        if(d == res.size()){
            res.push_back(root->val);
        }else{
            res[d] = max(res[d],root->val);
        }
        dfs(root->left,d+1);
        dfs(root->right,d+1);
    }
    vector<int> largestValues(TreeNode* root) {
        dfs(root,0);
        return res;
    }
};