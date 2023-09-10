class Solution {
public:
    vector<vector<int>>res;
    
    void twoSum(vector<int>&nums,int target,int i,int j){
        while(i < j){
            if(nums[i] + nums[j] > target)
                    j--;
            else if(nums[i] + nums[j] < target)
                    i++;
            else{
                // first we will remove duplicate from either end
                
                while(i<j and nums[i]  == nums[i+1])
                        i++;
                while(i<j and nums[j] == nums[j-1])
                        j--;
                res.push_back({-target,nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        res.clear();
        int n = nums.size();
        if(n < 3)
            return {};
        // sort
        sort(begin(nums),end(nums));
        //fix one element : n1
        for(int i=0;i<n;i++){
            if(i>0 and nums[i] == nums[i-1])
                continue;
            
            int target = -nums[i];
            // now call two sum
            twoSum(nums,target,i+1,n-1);
            // to find n2,n3 {n1,n2,n3}
        }
        return res;
    }
};