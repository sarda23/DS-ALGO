class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0,end=0,maxlen=0,flippedones=0;
        while(end<nums.size()){
            if(nums[end]==1)
                end++;
            else{
                // nums[end]==0
                if(flippedones<k){
                    end++;
                    flippedones++;
                }
                else{
                    // reduced some flippedones
                    while(flippedones>=k){
                        if(nums[start]==0)
                            flippedones--;
                        start++;
                    }
                }
            }
            maxlen=max(maxlen,end-start);
        }
        return maxlen;
    }
};