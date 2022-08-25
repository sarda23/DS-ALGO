class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        dp[0]=1;
        
        for(int i=1;i<n;i++){
            int mx=0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(dp[j]>mx)
                        mx=dp[j];
                }
            }
            dp[i]=mx+1;
        }
        return *max_element(dp.begin(),dp.end());
    }
};