class Solution {
public://pepcoding    using heap--we need max freq(map) char
    string reorganizeString(string s){
        priority_queue<pair<int,char>>maxh;
        unordered_map<char,int>mp;
        
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
        
        for(auto it:mp)
            maxh.push({it.second,it.first});
        
        string ans="";
        while(maxh.size()>1){
            auto [a,b] = maxh.top();
            maxh.pop();
            auto [c,d] = maxh.top();
            maxh.pop();
            ans.push_back(b);
            ans.push_back(d);
            a--;
            c--;
            if(a>0)
                maxh.push({a,b});
            if(c>0)
                maxh.push({c,d});
        }
        if(maxh.size()==1){
            auto [a,b]=maxh.top();
            maxh.pop();
            if(a>1)
                return "";
            ans.push_back(b);
        }
        return ans;
    }
};