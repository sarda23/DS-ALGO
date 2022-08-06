class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp; vector<int>ans;
        for(int i=0;i<nums.size();i++){
            int f=target-nums[i];
            if(mp.find(f)!=mp.end()){
                ans.push_back(i);
                ans.push_back(mp[f]);
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};