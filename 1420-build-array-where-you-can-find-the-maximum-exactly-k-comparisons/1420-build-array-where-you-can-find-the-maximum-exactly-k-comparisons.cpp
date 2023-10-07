class Solution {
public:
    int N,M,K;
    int mod = 1e9 + 7;
    int t[51][52][102];
    int solve(int idx,int searchCost, int maxSoFar){
        
        if(idx == N){
            if(searchCost == K){
                return 1;
            }
            return 0;
        }
        
        if(t[idx][searchCost][maxSoFar] != -1)
            return t[idx][searchCost][maxSoFar];
        
        int ans = 0;
        
        for(int i=1;i<=M;i++){
            if(i > maxSoFar){
                ans = (ans + solve(idx+1,searchCost+1,i))%mod;
            }
            else{
                ans = (ans + solve(idx+1,searchCost,maxSoFar))%mod;
            }
        }
        return t[idx][searchCost][maxSoFar] = ans%mod;
    }
    
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(t,-1,sizeof(t));
        return solve(0,0,0);
    }
};