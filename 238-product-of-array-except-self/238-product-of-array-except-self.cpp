class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(),p=1;
        vector<int>res(n,1);
        
        for(int i=1;i<n;i++){
            res[i]=(res[i-1]*nums[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            p*=nums[i+1];
            res[i]=(res[i]*p);
        }
       
        return res;
    }
};