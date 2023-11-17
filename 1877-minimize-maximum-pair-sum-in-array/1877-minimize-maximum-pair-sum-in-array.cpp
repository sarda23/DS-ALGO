class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),end(nums));
        
        int n = nums.size();
        int i=0,j=n-1;
        int mx=INT_MIN;
        while(i<j){
            int sum = nums[i] + nums[j];
            mx = max(mx,sum);
            i++;j--;
        }
        
        return mx;
    }
};