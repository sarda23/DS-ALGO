class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int start=0,end=n-1,mid;
        while(start<=end){
            mid=(start+end)>>1;
            int next=(mid+1)%n;
            int prev=(mid+n-1)%n;
            if(nums[start]<=nums[end]) // if both side is already sorted
                return nums[start];
            if(nums[mid]<=nums[next] and nums[prev]>=nums[mid])
                return nums[mid];
            else if(nums[start]<=nums[mid]) //go to the unsorted side
                start=mid+1;
            else if(nums[mid]<=nums[end])
                end=mid-1;
        }
        return -1;
    }
};