class Solution {
public:
    typedef pair<int,int>p;
    
    int bs(vector<int>&nums,int l,int r){
        int res = -1;
        int mid;
        
        while(l<=r){
            mid = l + (r-l)/2;
            
            if(nums[mid] == 1){
                res = mid;
                l = mid+1;
            }
            else
                r = mid -1;
        }
        return res+1;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int  n = mat.size();
        int m = mat[0].size();
        
        vector<p>count;
        
        for(int row = 0;row<n;row++){
            int num = bs(mat[row],0,m-1);
            count.push_back({num,row});
        }
        
        sort(begin(count),end(count));
        
        vector<int>res(k);
        
        for(int i=0;i<k;i++){
            res[i]= count[i].second;
        }
        return res;
    }
};