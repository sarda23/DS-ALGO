class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        
        vector<int>prev = nums[0];
        
        int count = 1;//atleast one arrow
        
        for(int i=1;i<n;i++){
            int currStartPoint = nums[i][0];
            int currEnd = nums[i][1];
            
            int prevstart = prev[0];
            int prevend = prev[1];
            
            if(currStartPoint > prevend){
                count++;
                prev = nums[i];
            }else{
                // overlap hai
                prev[0] = max(prevstart , currStartPoint);
                prev[1] = min(currEnd,prevend);
            }
        }
        return count;
    }
};