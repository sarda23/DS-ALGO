class Solution {
public:
    // pepcoding
    string longestPalindrome(string s) {
        int n=s.size(); string ans="";
        vector<vector<bool>>dp(n,vector<bool>(n));
        for(int g=0;g<n;g++){  // g-gap
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0)
                    dp[i][j]=true;
                else if(g==1){
                    if(s[i]==s[j])
                        dp[i][j]=true;
                    else
                        dp[i][j]=false;
                }
                else{
                    if(s[i]==s[j] and dp[i+1][j-1]==true)
                        dp[i][j]=true;
                    else
                        dp[i][j]=false;
                }
                if(dp[i][j]==true)
                    ans=s.substr(i,g+1);
            }
        }
        return ans;
    }
};