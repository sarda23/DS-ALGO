class Solution {
public:
    vector<vector<int>> ans;
    vector<int>temp;
    void solve(int k,int n,int sum,int index){
        if(sum==n and k==0){
            ans.push_back(temp);
            return;
        }
        if(sum>n)
            return;
        //normal backtracking tech
        for(int i=index;i<=9;i++){
            if(i>n)
                break;
            temp.push_back(i);
            solve(k-1,n,sum+i,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(k,n,0,1);
        return ans;
    }
};