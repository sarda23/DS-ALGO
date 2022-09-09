class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures){
        int n=temperatures.size();
        vector<int>ans(n);
        stack<int>s;
        
        for(int i=0;i<n;i++){
            
            while(!s.empty() and temperatures[s.top()]<temperatures[i]){
                //found an increasing value for stack top index
                ans[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};