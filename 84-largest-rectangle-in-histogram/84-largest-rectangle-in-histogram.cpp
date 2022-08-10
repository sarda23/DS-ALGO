class Solution {
public:
    int largestRectangleArea(vector<int>& arr){
        int ans=0,n=arr.size();
        vector<int>left,right,res;
        stack<pair<int,int>> s,ss;
        // first lets find the NSL
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
       /* for(int i=0;i<left.size();i++)
           cout<<right[i]<<" "<<left[i]<<" "; 
           */
        for(int i=0;i<n;i++){
            res.push_back((right[i]-left[i]-1)*arr[i]);
        }
        
        /*for(int i=0;i<left.size();i++)
           cout<<res[i]<<"  "; 
          */ 
        ans=*max_element(res.begin(),res.end());
        return ans;
    }
};