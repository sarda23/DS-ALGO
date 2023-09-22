class SummaryRanges {
public:
    unordered_set<int>st;
    SummaryRanges() {
        st.clear();
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<int>nums(begin(st),end(st));
        
        sort(begin(nums),end(nums));
        
        vector<vector<int>>res;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            int left = nums[i];
            
            while(i<n-1 and nums[i] + 1== nums[i+1]){
                i++;
            }
            res.push_back({left,nums[i]});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */