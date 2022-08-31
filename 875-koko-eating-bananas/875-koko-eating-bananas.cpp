class Solution {
public:
    bool ispossible(vector<int>&piles,int currentspeed,int h){
        long long time=0;
        for(int i=0;i<piles.size();i++){
            long long div=piles[i]/currentspeed;
            time+=div;
            if(piles[i]%currentspeed!=0)
                time++;
        }
        return time<=h?true:false;
    }
    int minEatingSpeed(vector<int>& piles, int h){
        int start =1;
        int end =*max_element(piles.begin(),piles.end());
        if(piles.size()==h)
            return end;
        int speed=end;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(ispossible(piles,mid,h))
                end=mid-1;
            else
                start=mid+1;
        }
        return start;
    }
};