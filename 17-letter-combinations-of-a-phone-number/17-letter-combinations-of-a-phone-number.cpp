class Solution {
public:
    void solve(vector<string>&ans,string &digit,vector<string>s,int index,string current){
        if(index==digit.size()){
            ans.push_back(current);
            return;
        }
        string possiblechar=s[digit[index]-'0'];
        for(char c:possiblechar){
            solve(ans,digit,s,index+1,current+c);
        }
    }
    vector<string> letterCombinations(string digits){
        // backtracking 
        vector<string>s(10);
        s[2]="abc"; s[3]="def";s[4]="ghi";s[5]="jkl";s[6]="mno";
        s[7]="pqrs";s[8]="tuv";s[9]="wxyz";
        
        vector<string>ans;
        if(digits=="" or digits.size()==0)
            return ans;
        solve(ans,digits,s,0,"");
        return ans;
    }
};