class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> res;
        unordered_map<int,int>mp;
        
        int n = changed.size();
        if(n%2 != 0)
            return {}; // empty array/vector
        
        sort(changed.begin(),changed.end());
        
        for(int &n : changed){
            mp[n]++;
        }
        
        for(int &num:changed){
            int twice = 2*num;
            
            if(mp[num] == 0)
                continue;
            // ya toh twice hai hi nahi ya toh uska freq 0 hai dono cases me possible nahi hai
            if(mp.find(twice) == mp.end() or mp[twice] == 0){
                return {};
            }
            
            res.push_back(num);
            mp[num]--;
            mp[twice]--;
        }
        
        return res;
    }
};