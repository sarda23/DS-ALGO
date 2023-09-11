class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        
        vector<vector<int>>res;
        // key -> val
        // size -> {}
        vector<vector<int>>mp(n+1); // n groups from 1 to n
        
        
        for(int i = 0;i<n;i++){
            int L = groupSizes[i];
            
            mp[L].push_back(i);
            if(mp[L].size() == L) // group mil chuka hai
            {
                res.push_back(mp[L]);
                mp[L] = {}; // empty kar dia
            }
        }
        return res;
    }
};