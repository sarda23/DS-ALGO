class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0,total=0;
        int n = gas.size();
        if(accumulate(gas.begin(),gas.end(),0) < accumulate(cost.begin(),cost.end(),0))
            return -1;
        
        for(int i=0;i<n;i++){
            total += gas[i] - cost[i];
            if(total<0){
                total = 0;
                ans = i+1;
            }
        }
        return ans;
    }
};