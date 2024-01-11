class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        
        if(sum %2 != 0)
            return false;
        
        int dp[sum/2 + 1]; memset(dp, 0, sizeof(dp));
        dp[0] = 1;
            
        for(int i = n - 1; i >= 0; i--){
            for(int target = sum/2; target >= 0; target--){
                if(target >= nums[i])
                    dp[target] |= dp[target - nums[i]];
            }
        }
        return dp[sum/2];
    }
};