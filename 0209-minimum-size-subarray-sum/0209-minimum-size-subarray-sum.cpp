class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i=0,j=0,n=nums.size();
        int ws = n;
        int total = accumulate(nums.begin(),nums.end(),0);
        
        if(total < target)
            return 0;
        
        int sum = 0;
        while(j < n){
            sum += nums[j];
            
            if(sum < target){
                j++;
            }
            else if(sum >= target){
                
                while(sum >= target){
                    ws = min(ws,j-i+1);
                    sum -= nums[i];
                    i++;
                }
                j++;
            }
        }
        return ws;
    }
};