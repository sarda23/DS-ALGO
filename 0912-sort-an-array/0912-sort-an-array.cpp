class Solution {
public:
    void merge(vector<int>&nums,int l,int mid,int r){
        vector<int> left,right;
        for(int i =l;i<=mid;i++){
            left.push_back(nums[i]);
        }
        for(int j=mid+1;j<=r;j++){
            right.push_back(nums[j]);
        }
        
        int i=l,j=0,k=0;
        
        while(j<left.size() and k<right.size()){
            if(left[j]<=right[k]){
                nums[i] = left[j];
                j++;
            }
            else{
                nums[i] = right[k];
                k++;
            }
            i++;
        }
        
        while(j<left.size()){
            nums[i] = left[j];
            j++;
            i++;
        }
        
        while(k<right.size()){
            nums[i] = right[k];
            k++;
            i++;
        }
    }
    void mergesort(vector<int>&nums,int l,int r){
        if(l == r)
            return;
        
        int mid = l +(r-l)/2;
        mergesort(nums,l,mid);
        mergesort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};