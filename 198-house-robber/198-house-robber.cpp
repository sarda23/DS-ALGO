class Solution {
public:
    int dp[110];
    int solve(vector<int>&nums,int i,int n){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int a=nums[i]+solve(nums,i+2,n);
        int b=solve(nums,i+1,n);
        return dp[i]=max(a,b);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,nums.size());
    }
};