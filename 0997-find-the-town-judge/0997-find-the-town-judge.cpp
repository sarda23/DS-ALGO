class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>in(n+1);
        vector<int>out(n+1);
        
        for(vector<int>&vec:trust){
            int u = vec[0];
            int v = vec[1];
            
            out[u]++;
            in[v]++;
        }
        for(int i=1;i<=n;i++){
            if(in[i] == n-1 and out[i] == 0)
                return i;
        }
        return -1;
    }
};