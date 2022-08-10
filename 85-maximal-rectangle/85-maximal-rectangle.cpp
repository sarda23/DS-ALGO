class Solution {
public:
    int mah(vector<int>v){
        int n=v.size();
        stack<pair<int,int>>s,ss;
        vector<int>left,right,res(n);
        // first lets cal the NSR
        for(int i=n-1;i>=0;i--){
            if(s.size()==0)
                right.push_back(n);
            else if(s.size()>0 and s.top().first<v[i])
                right.push_back(s.top().second);
            else if(s.size()>0 and s.top().first>=v[i]){
                while(s.size()>0 and s.top().first>=v[i])
                    s.pop();
                if(s.size()==0)
                    right.push_back(n);
                else
                    right.push_back(s.top().second);
            }
             s.push({v[i],i});   
        }
        reverse(right.begin(),right.end());
        // now we need to cal the NSL
          for(int i=0;i<n;i++){
            if(ss.size()==0)
                left.push_back(-1);
            else if(ss.size()>0 and ss.top().first<v[i])
                left.push_back(ss.top().second);
            else if(ss.size()>0 and ss.top().first>=v[i]){
                while(ss.size()>0 and ss.top().first>=v[i])
                    ss.pop();
                if(ss.size()==0)
                    left.push_back(-1);
                else
                    left.push_back(ss.top().second);
            }
             ss.push({v[i],i});   
        }
        for(int i=0;i<n;i++){
            res[i]=(right[i]-left[i]-1)*v[i];
        }
        return *max_element(res.begin(),res.end());
    }
    int maximalRectangle(vector<vector<char>>& matrix){
        int n=matrix.size(),m=matrix[0].size();
        vector<int>v;
        for(int i=0;i<m;i++)
            v.push_back(matrix[0][i]-'0');
        int mx=mah(v);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')
                    v[j]=0;
                else
                    v[j]+=matrix[i][j]-'0';
            }
            mx=max(mx,mah(v));
        }
        return mx;
    }
};