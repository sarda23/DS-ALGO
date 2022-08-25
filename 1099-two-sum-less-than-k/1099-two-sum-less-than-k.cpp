class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]<k)
                    mx=max(mx,nums[i]+nums[j]);
            }
        }
        return mx==INT_MIN?-1:mx;
    }
};