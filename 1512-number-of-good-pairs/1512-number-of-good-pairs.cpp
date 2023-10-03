class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
        
        unordered_map<int,int>mp;
        
        for(auto &i:nums)
            mp[i]++;
        
        for(auto &it:mp){
            int t = it.second;
            ans += t*(t-1)/2;
            
        }
        return ans;
    }
};