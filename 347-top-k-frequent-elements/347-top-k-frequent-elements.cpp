typedef pair<int,int>p;
class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp; 
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<p,vector<p>,greater<p>>minh;
        for(auto i:mp){
            minh.push({i.second,i.first});
            if(minh.size()>k){
                minh.pop();
            }
        }
        while(minh.size()>0){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};