class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        string res="";
        vector<bool>taken(26,false);
        vector<int>lastindex(26);
        
        for(int i=0;i<n;i++){
            lastindex[s[i] - 'a'] = i;
        }
        
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(taken[ch-'a'] == true)
                continue;
            
            while(res.length() > 0 and res.back() > ch and lastindex[res.back() - 'a'] > i){
                taken[res.back() - 'a'] = false;
                res.pop_back();
            }
            taken[ch-'a'] = true;
            res.push_back(ch);
        }
        return res;
    }
};