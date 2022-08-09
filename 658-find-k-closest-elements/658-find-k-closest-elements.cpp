class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;vector<pair<int,int>>temp;
        for(int i=0;i<arr.size();i++){
            temp.push_back({abs(arr[i]-x),i});
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<k;i++){
            ans.push_back(arr[temp[i].second]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};