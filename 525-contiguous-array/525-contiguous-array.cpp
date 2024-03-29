class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans=0,sum=0;
        unordered_map<int,int>mp;//sum--index
        mp[0]=-1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) // 0 is treated as -1
                sum+=-1;
            else if(nums[i]==1)
                sum+=1;
            
            if(mp.find(sum)!=mp.end()){
                int index=mp[sum];
                int len = i - index;
                ans=max(ans,len);
            }
            else
                mp[sum]=i;
        }
        return ans;
    }
};