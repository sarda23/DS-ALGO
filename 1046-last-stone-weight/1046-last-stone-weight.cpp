class Solution {
public:
    priority_queue<int>maxh;
    int lastStoneWeight(vector<int>& stones) {
        for(int i=0;i<stones.size();i++)
            maxh.push(stones[i]);
        while(maxh.size()>=2){
           int one = maxh.top();
           maxh.pop();
           int second = maxh.top();
           maxh.pop();
           if(one>second)
               maxh.push(one-second);
        }
        return maxh.size()!=0?maxh.top():0;    
    }
};