class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left=0,right=1,n=prices.size(),profit=0;
        while(right<n){
            if(prices[right]>prices[left]){
                profit=max(profit,prices[right]-prices[left]);
            }
            else
                left=right;
            right++;
        }
        return profit;
    }
};