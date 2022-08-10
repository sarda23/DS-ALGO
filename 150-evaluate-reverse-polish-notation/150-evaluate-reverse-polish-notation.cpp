class Solution {
public:
    bool isoperator(string t){
        return t=="*" or t=="/" or t=="+" or t=="-";
    }
    int evalRPN(vector<string>& tokens) {
        stack<string>s;
        for(auto t:tokens){
            if(isoperator(t)){
                int el2=stoi(s.top());s.pop();
                int el1=stoi(s.top());s.pop();
                int ans=0;
                if(t=="*")
                    ans=el1*el2;
                else if(t=="/")
                    ans=el1/el2;
                else if(t=="+")
                    ans=el1+el2;
                else if(t=="-")
                    ans=el1-el2;
                s.push(to_string(ans)+"");
            }
            else
                s.push(t);
        }
        return stoi(s.top());
    }
};