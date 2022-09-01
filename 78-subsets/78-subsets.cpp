class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(vector<int> &nums,int pos){
        ans.push_back(temp);
        
        for(int i=pos;i<nums.size();i++){
           // if(i>pos and nums[i]==nums[i-1])
             //   continue;
            temp.push_back(nums[i]);
            backtrack(nums,i+1);
            temp.pop_back();
        }  
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       // sort(nums.begin(),nums.end());
        backtrack(nums,0);
        return ans;
    }
};