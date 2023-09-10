class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        int ans=100000;
        
        for(int k=0;k<n-2;k++){//atleast 3 element
            int i = k+1;
            int j = n-1;
            // two pointer 
            while(i < j){
                int sum = nums[k] + nums[i] + nums[j];
                
                if(abs(target - sum) < abs(target - ans)){
                    ans = sum;
                }
                
                if(sum < target)
                    i++;
                else
                    j--;
            }
        }
        
        return ans;
    }
};