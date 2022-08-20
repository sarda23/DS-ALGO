class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long p=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)
                nums[i]=-1;
            else if(nums[i]==0)
                return 0;
            else
                nums[i]=1;
            p*=nums[i];
        }
        if(p!=0)
            return p>0?1:-1;
        return 0;
    }
};