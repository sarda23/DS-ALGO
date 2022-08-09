class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;priority_queue<pair<int,int>>maxh;
        for(int i=0;i<arr.size();i++){
            maxh.push({abs(x-arr[i]),i});
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        while(maxh.size()>0){
            ans.push_back(arr[maxh.top().second]);
            maxh.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};