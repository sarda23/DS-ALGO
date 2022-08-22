class Solution {
public:
    int missingNumber(vector<int>& nums) {
        set<int>s;
        for(auto i:nums)
            s.insert(i);
        for(int i=0;i<=nums.size();i++){
            if(s.find(i)!=s.end())
                continue;
            else
                return i;
         }
        return 0;
    }
};