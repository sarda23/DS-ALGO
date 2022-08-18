class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
         if(k == 0 )
            return k;
        int res = 0;
        int temp = 0;
        int n = s.length();
        int i = 0, j = 0;
        map<char,int> mp;
        while(j < n)
        {
            mp[s[j]]++;
            if(mp.size() <= k)
            {
                res = res > j-i+1 ? res : j-i+1;
                j++;
            }
            else if(mp.size() > k)
            {
                while(mp.size() > k)
                {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0)
                        mp.erase(s[i]);
                    
                    i++;
                }
                j++;
            }
        }
        return res;
    }
};