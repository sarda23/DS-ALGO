class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(auto a:nums)
            ans.push_back(a);
        return ans;
    }
};