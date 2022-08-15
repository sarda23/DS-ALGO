class Solution {
public:
    int bs(vector<int>&nums,int start,int end){
        int n=nums.size();
        int mid;
        while(start<=end){
            mid=(start+end)>>1;
            int next=(mid+1)%n; // so that we don't go out of bound
            int prev=(mid+n-1)%n;
            if(nums[start]<=nums[end]) // if both side is already sorted
                return start;
            else if(nums[mid]<=nums[next] and nums[prev]>=nums[mid])
                return mid;
            else if(nums[start]<=nums[mid]) //go to the unsorted side
                start=mid+1;
            else if(nums[mid]<=nums[end])
                end=mid-1;
        }
        return -1;
    }
    int solve(vector<int>&nums,int target,int start,int end){
        while(start<=end){
            int mid=(start+end)>>1;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int index=bs(nums,0,nums.size()-1); // finding the minimum element in a rotated sorted array
        
        int a=solve(nums,target,0,index-1);
        int b=solve(nums,target,index,nums.size()-1);
        return a==-1?b:a;
    }
};