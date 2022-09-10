class Solution {
public:
    // monotonic stack     coding decoded
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int>s;
        unordered_map<int,int>mp;
        vector<int>ans;
        
        for(auto el:nums2){
            while(!s.empty() and s.top()<el){
                int tp=s.top();
                mp[tp]=el;
                s.pop();
            }
            s.push(el);
        }
        for(auto i:nums1){
            if(mp.find(i)!=mp.end())
                ans.push_back(mp[i]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};