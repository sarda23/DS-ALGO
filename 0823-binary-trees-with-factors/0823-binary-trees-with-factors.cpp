class Solution {
public:
    int mod = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr),end(arr));
        
        unordered_map<int,long long>mp;
        
        mp[arr[0]] = 1;
        
        for(int i=1;i<n;i++){
            int root = arr[i];
            mp[root] = 1;
            
            for(int j=0;j<i;j++){
                int lc = arr[j];
                //rc = arr[i]/lc
                if(root%lc == 0 && mp.find(arr[i]/lc) != mp.end()){
                    mp[root] += mp[lc]*mp[arr[i]/lc];
                }
            }
        }
        long res = 0;
        for(auto &it:mp){
            res = (res+it.second)%mod;
        }
        return res;
    }
};