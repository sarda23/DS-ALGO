class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,n=nums.size(),mx=0,len=0;
        while(i<n){
            if(nums[i]==1){
                len++;
                mx=max(mx,len);
            }
            else if(nums[i]==0){
                len=0;
            }
            i++;
        }
        return mx;
    }
};