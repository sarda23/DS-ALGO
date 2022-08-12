class Solution {
public:
    static bool comp(string a,string b){
        return a+b>b+a;
    }
    string largestNumber(vector<int>& nums){
        vector<string>arr;
        for(auto i:nums)
            arr.push_back(to_string(i));
        sort(arr.begin(),arr.end(),comp);
        string ans;
        for(auto i:arr){
            ans+=i;
        }
        while(ans[0]=='0' && ans.length()>1)
            ans.erase(0,1);
        return ans;
    }
};