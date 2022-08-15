/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int find_peak(MountainArray &nums){
        int n=nums.length();
        if(n==1)
            return 0;
        int start=0,end=n-1;
        while(start<=end){
            int mid=(start+end)/2;
            int search=nums.get(mid);
            if(mid>0 and mid<n-1){    
                 if(search>nums.get(mid-1) and search>nums.get(mid+1))
                    return mid;
                else if(search<nums.get(mid-1))
                    end=mid-1;
                else if(search<nums.get(mid+1))
                    start=mid+1;
            }
            else if(mid==0){
                if(search<nums.get(1))
                    return 1;
                else
                    return 0;
            }
            else {                      // mid==n-1
                if(search<nums.get(mid-1))
                    return mid-1;
                else
                    return mid;
            }
        }
        return 0;
    }
    int bsi(int start,int end,int target,MountainArray &nums){
        while(start<=end){
            int mid=(start+end)>>1;
            int search=nums.get(mid);
            if(search==target)
                return mid;
            else if(search<target)
                start=mid+1;
            else
                end=mid-1;
        }
        return -1;
    }
    int bsd(int start,int end,int target,MountainArray &nums){
        while(start<=end){
            int mid=(start+end)>>1;
            int search=nums.get(mid);
            if(search==target)
                return mid;
            else if(search<target)
                end=mid-1;
            else
                start=mid+1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int index=find_peak(mountainArr); //got the index of the peak element
    
        int n=mountainArr.length();
        int left=bsi(0,index,target,mountainArr);
        if(left!=-1)
            return left;
        else
            return bsd(index+1,n-1,target,mountainArr);    
        return -1;
    }
};