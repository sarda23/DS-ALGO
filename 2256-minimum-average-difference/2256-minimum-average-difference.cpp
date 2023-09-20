class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        
        long long total=0;
        
        for(int i=0;i<n;i++)
            total+=nums[i];
        long long sum = 0;
        int mad=INT_MAX;
        int idx = -1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            long long remain = total - sum;
            
            long long avg1 = sum/(i+1);
            long long avg2 = (i==n-1)?0:remain/(n-1-i) ;
            
            if(abs(avg1-avg2) < mad){
                mad = abs(avg1-avg2);
                idx = i;
            }
            
        }
        
        return idx;
    }
};