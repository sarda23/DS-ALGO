class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp,comp;
        for(auto i:s)
            mp[i]++;
        
        for(auto i:t)
            comp[i]++;
        
        if(mp==comp)
            return true;
        return false;
    }
};