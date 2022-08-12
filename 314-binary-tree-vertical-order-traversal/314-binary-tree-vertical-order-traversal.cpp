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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        map<int,vector<int>>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(q.size()){
            auto it=q.front(); q.pop();
            TreeNode* temp=it.first;
            int line=it.second;
            mp[line].push_back(temp->val);
            
            if(temp->left)
                q.push({temp->left,line-1});
            if(temp->right)
                q.push({temp->right,line+1});
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};