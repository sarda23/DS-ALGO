class Solution {
public:
    int lbs(vector<int>&nums,int target){
        int n = nums.size();
        int start =  0, end    = n-1;
        int second = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(target == nums[mid]){
                second = mid;
                start   = mid+1;
            }else if(nums[mid] > target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return second;
    }
    int fbs(vector<int>&nums,int target){
        int n = nums.size();
        int start =  0, end    = n-1;
        int first = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(target == nums[mid]){
                first = mid;
                end   = mid-1;
            }else if(nums[mid] > target){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return first;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return {fbs(nums,target) , lbs(nums,target)};
    }
};