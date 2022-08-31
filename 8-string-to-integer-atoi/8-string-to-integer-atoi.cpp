class Solution {
public:
    int myAtoi(string s) {
        int i=0,no=0; 
        bool neg=false;
        
        while(i<s.size() and s[i]==' ')
            i++;
        
        if(i<s.size() and s[i]=='-'){
            neg=true;
            i++;
        }
        else if(i<s.size() and s[i]=='+')
            i++;
        
        // now everything has to be a number
        while(i<s.size() and isdigit(s[i])){
            int c=s[i]-'0';
            if((INT_MAX-c)/10<no){
                if(neg)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
            no=no*10+c;
            i++;
        }
        if(no==0)
            return 0;
        else{
            if(neg)
                return -no;
            else
                return no;
        }
    }
};