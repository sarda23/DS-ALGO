class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        unordered_map<int,int>mp;
        int sum = 0;
        
        mp[0] = -1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mp[sum] = i;
        }
        
        if(sum < x)
            return -1;
        
        int remain_sum = sum - x;
        int longest = INT_MIN;
        
        sum = 0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int find = sum - remain_sum;
            if(mp.find(find) != mp.end()){
                int idx = mp[find];
                longest = max(longest,i-idx);
            }
        }
        return longest==INT_MIN?-1:n-longest;
    }
};