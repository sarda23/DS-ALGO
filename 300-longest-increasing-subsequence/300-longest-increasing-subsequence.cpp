class Solution {
public:
    int dp[2501];
    int lis(int index,vector<int>&nums){
        if(dp[index]!=-1)
            return dp[index];
        int ans=1;
        for(int i=0;i<index;i++){
            if(nums[index]>nums[i])
                ans=max(ans,lis(i,nums)+1);
        }
        return dp[index]=ans;
    }
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,lis(i,nums));
        }
        return ans;
    }
};