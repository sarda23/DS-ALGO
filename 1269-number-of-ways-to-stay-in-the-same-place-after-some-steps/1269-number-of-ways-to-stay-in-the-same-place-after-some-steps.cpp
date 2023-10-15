class Solution {
public:
    int n;
    int t[501][501];
    int mod = 1e9 + 7;
    //O(3^n)
    //O(arrLen*steps) -- memoize  
    int solve(int idx,int steps){
        if(idx<0 or idx >=n)
            return 0;
        
        if(steps == 0){
            return idx == 0;
        }
        
        if(t[idx][steps] != -1)
            return t[idx][steps];
        
        int res = solve(idx+1,steps-1); // right
        
        res = (res + solve(idx-1,steps-1))%mod;  // left
        
        res = (res + solve(idx,steps-1))%mod; // stay
        
        return t[idx][steps] = res;
    }
    
    int numWays(int steps, int arrLen) {
        arrLen = min(steps/2 + 1,arrLen);
        memset(t,-1,sizeof(t));
        n = arrLen;
        
        return solve(0,steps);
    }
};