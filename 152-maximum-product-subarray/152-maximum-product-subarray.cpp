class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxsofar=nums[0],minsofar=nums[0],res=nums[0];
        for(int i=1;i<n;i++){
            int copymaxsofar=maxsofar;
            int el=nums[i];
            maxsofar=max(el,max(el*maxsofar,el*minsofar));
            
            minsofar=min(el,min(el*copymaxsofar,el*minsofar));
            
            res=max(res,maxsofar);
        }
        return res;
    }
};