class Solution {
public:
    string maxValue(string n, int x) {
        int len=n.size();
        int ans=len;
        if(n[0]=='-'){ // negative number
            for(int i=len-1;i>=1;i--)
                if(n[i]-'0'>x)
                    ans=i;
        }
        else{
            for(int i=len-1;i>=0;i--)
                if(n[i]-'0'<x)
                    ans=i;
        }
        n.insert(n.begin()+ans,x+'0');
        return n;
    }
};