class Solution {
public:
    int bs(vector<int>&nums,int n,int target){
        int l=0,r=n-1;
        int mid;
        
        int res_idx = -1;
        
        while(l<=r){
            mid = l + (r-l)/2;
            
            if(nums[mid] <= target){
                res_idx = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return res_idx+1;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        
        vector<int>res;
        //cumulative sum
        for(int i=1;i<n;i++)
            nums[i] += nums[i-1];
        
        for(int &q:queries){
            int count = bs(nums,n,q);
            
            res.push_back(count);
        }
        return res;
    }
};