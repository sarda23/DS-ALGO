class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i =0,j=0;
        int n = s.size(),m=t.size();
        
        map<char,vector<int>>mp;
        
        for(int i=0;i<m;i++){
            mp[t[i]].push_back(i);
        }
        
        int prev = -1;
        
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(mp.find(ch) == mp.end())
                return false;
            
            vector<int>indices = mp[ch];
            
            auto it = upper_bound(begin(indices),end(indices),prev);
            if(it == indices.end())
                return false;
            
            prev = *it;
        }
        return true;
    }
};