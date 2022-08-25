class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int mx=-1;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int sum=0;
        
        while(i<j){
            sum=nums[i]+nums[j];
            if(sum<k){
                mx=max(mx,sum);
                i++;
            }
            else
                j--;
        }
        return mx;
    }
};