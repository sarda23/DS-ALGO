class Solution {
public:
     bool possible(int mid,vector<int> & weights,int days){
        int sum=0,count=1;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]<=mid)
                sum+=weights[i];
            else{
                count++;
                if(weights[i]>mid || count>days)
                    return 0;
                sum=weights[i];
            }
        }
         return 1;
     }
     // nums -- weights , m == days 
    // same questions as -- book allocations   and leetcode 1011    
    int splitArray(vector<int>& weights, int days) {
        int n=weights.size();
        if(n==1)
            return 0;
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=weights[i];
        
        int start=1,end=sum;
        while(start<=end){
            int mid=(start+end)/2;
            if(possible(mid,weights,days))
                end=mid-1;
            else
                start=mid+1;
        }
        return start;
    }
};