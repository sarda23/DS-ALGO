class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int total=a+b+c;
        int currA=0,currB=0,currC=0;
        string ans="";
        while(total--){
            if((a>=b and a>=c and currA!=2)||(a>0 and (currB==2 || currC==2))){
                ans+='a';
                a--;
                currA++;
                currB=currC=0;
            }
            else if((b>=a and b>=c and currB!=2)||(b>0 and (currA==2 || currC==2))){
                ans+='b';
                b--;
                currB++;
                currA=currC=0;
            }
            else if((c>=a and c>=b and currC!=2)||(c>0 and (currA==2 || currB==2))){
                ans+='c';
                c--;
                currC++;
                currA=currB=0;
            }
        }
        return ans;
    }
};