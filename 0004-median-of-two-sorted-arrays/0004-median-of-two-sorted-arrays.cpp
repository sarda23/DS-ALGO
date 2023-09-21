class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int sz = n+m;
        vector<int>temp(n+m);
        
        int i = 0, j =0,k=0;
        
        while(i<n and j<m){
            if(nums1[i] <= nums2[j]){
                temp[k++] = nums1[i++];
                
            }else{
               temp[k++] = nums2[j++];
            }
        }
        while(i<n){
            temp[k++] = nums1[i++];
                
        }
        while(j<m){
            temp[k++] = nums2[j++];
        }
        if((n+m)%2 == 1)
            return temp[(n+m)/2];
        
        return (temp[(n+m)/2] + temp[(n+m)/2 - 1])/2.0;
        
    }
};