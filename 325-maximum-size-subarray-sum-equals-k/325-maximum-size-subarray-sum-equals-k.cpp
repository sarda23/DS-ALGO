class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        // frequency map 
        unordered_map<long long,int>mp; 
        int ans=0;long long sum=0; 
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k)
                ans=max(ans,i+1);
            if(mp.find(sum-k)!=mp.end()){
                ans=max(ans,i-mp[sum-k]);
            }
            if(mp.find(sum)==mp.end())
                mp[sum]=i;
        }
        return ans;
    }
};