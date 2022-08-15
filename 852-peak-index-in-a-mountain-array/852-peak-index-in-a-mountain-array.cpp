class Solution {
public:
    // same as finding peak element -- leetcode 162
    int peakIndexInMountainArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        int start=0,end=n-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(mid>0 and mid<n-1){    
                 if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1])
                    return mid;
                else if(nums[mid]<nums[mid-1])
                    end=mid-1;
                else if(nums[mid]<nums[mid+1])
                    start=mid+1;
            }
            else if(mid==0){
                if(nums[0]<nums[1])
                    return 1;
                else
                    return 0;
            }
            else {                      // mid==n-1
                if(nums[mid]<nums[mid-1])
                    return mid-1;
                else
                    return mid;
            }
        }
        return 0;
    }
};