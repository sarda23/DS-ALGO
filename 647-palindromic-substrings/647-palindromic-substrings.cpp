class Solution {
public:
    /*bool ispalindrome(string ss){
        int i=0,j=ss.size()-1;
        while(i<=j){
            char ch1 = ss[i],ch2=ss[j];
            if(ch1!=ch2)
                return false;
            else{
                i++;j--;
            }
        }
        return true;
    }*/
    int countSubstrings(string s){
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n));
        int count=0;
        for(int g=0;g<n;g++){
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
                    count++;
            }
        }
        return count;
        
      
       /*int c=0;
       for(int i = 0; i < s.length(); i++){
           string substr;
           for (int j = i; j < s.length(); j++){    // Second loop is generating sub-string
                substr += s[j];
                //cout<<substr<<endl;
                if(ispalindrome(substr))
                    c++;
        `   }
        }
        return c;*/
        
    }
};