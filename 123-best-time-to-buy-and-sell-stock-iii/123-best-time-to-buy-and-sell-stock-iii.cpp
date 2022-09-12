class Solution {
public:
    int maxProfit(vector<int>& price) {
        vector<long int>dp(5, INT_MIN);
        dp[0]=0;
        for(int i=0;i<price.size();i++)
        {
            vector<long int> temp(5);
            temp = dp;

            dp[1]=max(temp[1], temp[0]-price[i]);
            dp[2]=max(temp[2], temp[1]+price[i]);
            dp[3]=max(temp[3], temp[2]-price[i]);
            dp[4]=max(temp[4], temp[3]+price[i]);
        }
        
        return (int)max(dp[0], max(dp[2], dp[4]));
    }
};