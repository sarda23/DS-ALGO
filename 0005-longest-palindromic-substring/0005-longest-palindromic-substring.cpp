class Solution {
public:
    bool solve(string &s,int i,int j){
        if(i>=j){
            return true;
        }
        
        if(s[i] == s[j]){
            return solve(s,i+1,j-1);
        }
        
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        
        int maxL = INT_MIN;
        
        int startP = 0;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j) == true){
                    if(j-i+1 > maxL){
                        maxL = j-i+1;
                        startP = i;
                    }
                }
            }
        }
        return s.substr(startP,maxL);
    }
};