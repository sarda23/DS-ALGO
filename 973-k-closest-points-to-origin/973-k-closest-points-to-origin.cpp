typedef pair<int,pair<int,int>>p;
class Solution{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<p>maxh;
        for(int i=0;i<points.size();i++){
            int x=points[i][0],y=points[i][1];
            maxh.push({x*x+y*y,{x,y}});
            if(maxh.size()>k)
                maxh.pop();
        }
        while(maxh.size()>0){
            ans.push_back({maxh.top().second.first,maxh.top().second.second});
            maxh.pop();
        }
        return ans;
    }
};