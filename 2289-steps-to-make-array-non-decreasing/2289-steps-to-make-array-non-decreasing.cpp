class Solution {
public:
    // coding decoded
    // monotonic stack
    int totalSteps(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        
        stack<pair<int,int>>s;
        s.push({nums[n-1],0});
        for(int i=n-2;i>=0;i--){
            int count=0;
            while(!s.empty() and nums[i]>s.top().first){
                count=max(count+1,s.top().second);
                s.pop();
            }
            ans=max(ans,count);
            s.push({nums[i],count});
        }
        return ans;
    }
};