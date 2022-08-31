class Solution {
public:
    int findMaxLength(vector<int>& arr) {
       int N=arr.size();
       for(int i=0;i<N;i++){
           if(arr[i]==0)
               arr[i]=-1;
       }
       unordered_map<int,int> mp;
       int sum=0;
       int ans=INT_MIN;
       for(int i=0;i<N;++i){
           sum+=arr[i];
           
           if(sum==0)
               ans=max(ans,i+1);
           
           if(mp.find(sum)==mp.end()){
               mp[sum]=i;
           }
           else{
               ans=max(ans,i-mp[sum]);
           }
       }
       if(ans==INT_MIN)
           return 0;
       else
           return ans;
    }
};