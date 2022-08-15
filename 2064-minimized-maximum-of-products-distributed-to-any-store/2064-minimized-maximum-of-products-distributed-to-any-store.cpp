class Solution {
public:
    // same as leetcode 1011
     bool possible(int capacity,vector<int> & quantities,int store){
        int count=0;
        for(int i=0;i<quantities.size();i++){
            if(quantities[i]<=capacity)
                count++;
            else{
                int temp=quantities[i];
                while(temp>0){
                    temp-=capacity;
                    count++;
                }
            }
            if(count>store)
                return false;
            
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int sz=quantities.size();
       
        
        int start=1,end=end=*max_element(quantities.begin(),quantities.end()),ans=INT_MAX;
        while(start<=end){
            int mid=(start+end)/2;
            if(possible(mid,quantities,n)){
                end=mid-1;
                ans=min(mid,ans);
            }
            else
                start=mid+1;
        }
        return ans;
    }
};