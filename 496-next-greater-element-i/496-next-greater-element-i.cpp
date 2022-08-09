class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int>s;
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=n-1;i>=0;i--){    //find NGE for numbs2
            if(s.size()==0)
                mp[nums2[i]]=-1;
            else if(s.size()>0 and s.top()>nums2[i])
                mp[nums2[i]]=s.top();
            else if(s.size()>0 and s.top()<=nums2[i]){
                while(s.size()>0 and s.top()<=nums2[i])
                    s.pop();
                if(s.size()==0)
                    mp[nums2[i]]=-1;
                else
                    mp[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }
        for(auto i:nums1){
                ans.push_back(mp[i]);
        }
        return ans;
    }
};