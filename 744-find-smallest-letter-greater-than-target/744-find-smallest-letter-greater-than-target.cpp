class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char target) {
        int n=arr.size();
        int start=0,end=n-1;char res=arr[0];
        while(start<=end){
            int mid=(start+end)>>1;
            if(arr[mid]==target)
                start=mid+1;
            else if(arr[mid]<target)
                start=mid+1;
            else{
                res=arr[mid];
                end=mid-1;
            }
        }
        return res;
    }
};