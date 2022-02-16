class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        priority_queue<pair<int,pair<int,int>>> maxh; 
        vector<vector<int>> ans; 
        for(int i=0;i<arr.size();i++){
            int cal = arr[i][0]*arr[i][0] + arr[i][1]*arr[i][1]; 
            maxh.push({cal,{arr[i][0],arr[i][1]}});
            if(maxh.size()>k)
                maxh.pop();
        }
        while(maxh.size()>0){
            
               ans.push_back({maxh.top().second.first,maxh.top().second.second});
            maxh.pop();
        }
        return ans;
    }
};
