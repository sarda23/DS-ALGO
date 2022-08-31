class Solution{
public:
    int mx=0;
    vector<int>sum;
    Solution(vector<int>& w){
        int n=w.size();
        sum.resize(n);
        sum[0]=w[0];
        for(int i=1;i<n;i++)
            sum[i]=sum[i-1]+w[i];
        
        mx=sum[n-1];
    }
    int pickIndex(){
        int n=sum.size();
        int start=0,end=sum.size()-1;
        int range=sum[n-1];
        int target = 1 + rand()%range;
        while(start<=end){
            int mid=start +(end-start)/2;
            if(sum[mid]==target)
                return mid;
            else if(sum[mid]<target)
                start=mid+1;
            else
                end=mid-1;
        }
        return start;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */