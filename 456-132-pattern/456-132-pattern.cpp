class Solution {
public:
    // monotonic decreasing stack 
    // neetcode
    bool find132pattern(vector<int>& nums){
        stack<pair<int,int>>s;
        int curmin=nums[0];
        
        for(int i=1;i<nums.size();i++){
            while(!s.empty() and nums[i]>=s.top().first)
                s.pop();
            if(!s.empty() and nums[i]>s.top().second)
                return true;
            
            s.push({nums[i],curmin});
            curmin=min(curmin,nums[i]);
        }
        return false;
    }
};