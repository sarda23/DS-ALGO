class Solution {
public:
    int first=-1,last=-1;
    int bs(vector<int>&nums,int target,string search){
        int start=0,end=nums.size()-1,res=-1;
        while(start<=end){
            int mid=(start+end)>>1;
            if(nums[mid]==target){
                res=mid;
                if(search=="first")
                    end=mid-1;
                if(search=="last")
                    start=mid+1;
            }
            else if(nums[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        return {bs(nums,target,"first"),bs(nums,target,"last")};
    }
};