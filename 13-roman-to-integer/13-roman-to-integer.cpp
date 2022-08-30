class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp;
        mp['I']=1; mp['V']=5; mp['X']=10; mp['L']=50; mp['C']=100; mp['D']=500;
        mp['M']=1000;
        
        int no=0;
        for(int i=s.size()-1;i>=0;i--){
            char ch =s[i];
            int currno=mp[ch];
            if(i!=s.size()-1){
                char charnext=s[i+1];
                
                if(ch=='I' and ((charnext=='V')or(charnext=='X')))
                    no=no-currno;
                else if(ch=='X' and ((charnext=='L')or(charnext=='C')))
                    no=no-currno;
                else if(ch=='C' and ((charnext=='M')or(charnext=='D')))
                    no=no-currno;
                else
                    no=no+currno;
            }
            else
                no=no+currno;
        }
        return no;
    }
};