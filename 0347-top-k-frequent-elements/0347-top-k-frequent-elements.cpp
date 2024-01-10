class Solution {
public:
    typedef pair<int,int>P;
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        
        for(int &num:nums){
            mp[num]++;
        }
        
        // 2. define min heap
        priority_queue<P,vector<P>,greater<P>>pq;
        
        for(auto &it:mp){
            
            int value = it.first;
            int freq  = it.second;
            
            pq.push({freq,value});
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int> res;
        while(!pq.empty()){
            
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};