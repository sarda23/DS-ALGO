class Solution {
public:
    int mah(vector<int> arr){
        stack<pair<int,int>> s,ss;
        vector<int> left,right,res;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(s.size()==0)
              left.push_back(-1);
            else if(s.size()>0&&s.top().first<arr[i])
              left.push_back(s.top().second);
            else if(s.size()>0&&s.top().first>=arr[i]){
                while(s.size()>0&&s.top().first>=arr[i])
                   s.pop();
                if(s.size()==0)
                  left.push_back(-1);
                else
                  left.push_back(s.top().second);
            }
            s.push({arr[i],i});
        }
        // nsr
        for(int i=n-1;i>=0;i--){
            if(ss.size()==0)
              right.push_back(n);
            else if(ss.size()>0&&ss.top().first<arr[i])
              right.push_back(ss.top().second);
            else if(ss.size()>0&&ss.top().first>=arr[i]){
                while(ss.size()>0&&ss.top().first>=arr[i])
                   ss.pop();
                if(ss.size()==0)
                  right.push_back(n);
                else
                  right.push_back(ss.top().second);
            }
            ss.push({arr[i],i});
        }
        reverse(right.begin(),right.end());
        for(int i=0;i<n;i++)
            res.push_back((right[i]-left[i]-1)*arr[i]);
        return *max_element(res.begin(),res.end());
    }
    int maximalRectangle(vector<vector<char>>& M) {
        vector<int> v;
        int n=M.size(),m=M[0].size();
        for(int i=0;i<m;i++)
           v.push_back(M[0][i]-'0');
        int mx=mah(v); 
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]=='0')
                  v[j]=0;
                else
                  v[j]+=M[i][j]-'0';
            }
            mx=max(mx,mah(v));
        }
        return mx;
    }
};