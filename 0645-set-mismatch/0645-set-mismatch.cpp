class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        
        for(int &x:nums)
            mp[x]++;
        int miss;
        for(int i=1;i<=n;i++){
            if(mp.find(i) == mp.end())
                miss = i;
            else
                mp[i]--;
        }
        int dup;
        for(auto &it:mp)
            if(it.second > 0)
                dup = it.first;
        
        return {dup,miss};
    }
};