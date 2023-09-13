class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        for(int &x:nums)
            sum += x;
        
        int cs = 0;
        for(int i=0;i<n;i++){
            int leftsum = cs;
            int rightsum = sum - leftsum - nums[i];
            
            if(leftsum == rightsum)
                return i;
            
            cs+=nums[i];
        }
        return -1;
    }
};