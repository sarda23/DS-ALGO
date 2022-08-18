class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
         if(k == 0 )
            return k;
        unordered_map<char,int> mp;
        int i=0,j=0,mx=0,n=s.size();
        while(j<n){
            mp[s[j]]++;
            if(mp.size()<=k){
                mx=max(mx,j-i+1);
                j++;
            }     
            else if(mp.size()>k){
                while(mp.size()>k){
                      mp[s[i]]--;
                    if(mp[s[i]]==0)
                      mp.erase(s[i]);
                    i++;   
                 }
                 j++;
            }
        }
        return mx;
    }
};