class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==1)
            return 1;
        vector<int>start(n),end(n);
        for(int i=0;i<n;i++){
            start[i]=intervals[i][0];
            end[i]=intervals[i][1];
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        
        int res=0,count=0;
        int s=0,e=0;
        
        while(s<n){
            if(start[s]<end[e]){
                s++;
                count++;
            }
            else{
                e++;
                count--;
            }
            res=max(res,count);
        }
        return res;
    }
};