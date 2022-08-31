class Solution {
public:
    string decodeString(string sd){
        stack<string>s;
        int curnum=0;
        string curstring="";
        for(auto ch:sd){
            if(ch=='['){
                s.push(curstring);
                s.push(to_string(curnum));
                curstring="";
                curnum=0;
            }
            else if(ch==']'){
                string t=s.top(); s.pop();
                int num=stoi(t);
                string prevstring=s.top(); s.pop();
                string temp="";
                while(num--)
                    temp+=curstring;
                curstring=prevstring+temp;
            }
            else if(isdigit(ch))
                curnum=curnum*10+ch-'0';
            else
                curstring+=ch;
        }
        return curstring;
    }
};