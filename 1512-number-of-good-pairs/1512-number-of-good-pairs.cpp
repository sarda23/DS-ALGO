class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans=0;
        int n = nums.size();
        
        unordered_map<int,int>mp;
        
        for(auto &i:nums){
            if(mp.find(i) != mp.end()){
                ans += mp[i];
            }
            mp[i]++;
        }
                    
        return ans;
    }
};