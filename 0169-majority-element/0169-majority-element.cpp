class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int count = 0;
        int mj = NULL;
        
        for(int i=0;i<n;i++){
            
            if(count==0){
                count = 1;
                mj = nums[i];
            }else if(nums[i] == mj){
                count++;
            }else{
                count--;
            }
        }
        // no need to verify -- questions it is given that
        // answer is always present
        
        return mj;
    }
};