class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string>temp;
        unordered_map<string,vector<string>>mp; 
        for(auto str:strs){
            string temp = str;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(str);
        }
        for(auto vec:mp)
            ans.push_back(vec.second);
        return ans;
    }
};