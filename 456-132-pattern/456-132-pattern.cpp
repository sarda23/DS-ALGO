class Solution {
public:
    // monotonic decreasing stack 
    // coding decoded
    bool find132pattern(vector<int>& nums){
        stack<int>s;
        int secondmax=INT_MIN;
        
        for(int i=nums.size()-1;i>=0;i--){
            
            if(nums[i]<secondmax)
                return true;
            
            while(!s.empty() and nums[i]>s.top()){
                
                secondmax=max(secondmax,s.top());
                s.pop();
            }
            // all the peak element
            s.push(nums[i]);
        }
        return false;
    }
};