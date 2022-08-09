class Solution {
public:
    priority_queue<int,vector<int>,greater<int>>minh;
    int findKthLargest(vector<int>& nums, int k){
        for(int i=0;i<nums.size();i++){
            minh.push(nums[i]);
            if(minh.size()>k)
                minh.pop();
        }
        return minh.top();
    }
};