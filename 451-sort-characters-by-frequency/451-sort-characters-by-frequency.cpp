class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>maxh;
        for(auto i:s)
            mp[i]++;
        for(auto i:mp){
            maxh.push({i.second,i.first});
        }
        while(maxh.size()>0){
            int c=maxh.top().first;
            while(c--)
                ans.push_back(maxh.top().second);
            maxh.pop();
        }
        return ans;
    }
};