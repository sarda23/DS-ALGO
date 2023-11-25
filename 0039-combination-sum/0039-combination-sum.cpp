class Solution {
public:
    int n;
    vector<vector<int>> res;
    
    void solve(int idx, int target,vector<int>&candidates,vector<int>temp){
        
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(target < 0)
            return;
        
        for(int i=idx;i<n;i++){
            temp.push_back(candidates[i]);
            solve(i,target - candidates[i],candidates,temp);
            temp.pop_back();
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int>temp;
        
        solve(0,target,candidates,temp);
        
        return res;
    }
};