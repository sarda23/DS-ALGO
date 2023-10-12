class Solution {
public:
    typedef pair<int,pair<int,int>>P;
    
    vector<vector<int>>directions{{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(n == 0 or m == 0 or grid[0][0] == 1)
            return -1;
        
        auto isSafe = [&](int x,int y){
            return x >=0 && x<n && y>=0 &&y<m;
        };
        
        vector<vector<int>>res(n,vector<int>(m,INT_MAX));
        
        priority_queue<P,vector<P>,greater<P>>pq;
        
        pq.push({0,{0,0}});
        res[0][0] = 0;
        
        while(!pq.empty()){
            int d = pq.top().first;
            pair<int,int>node = pq.top().second;
            int x = node.first;
            int y = node.second;
            pq.pop();
            
            for(auto &dir:directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                
                int dist = 1;
                
                if(isSafe(x_,y_) && grid[x_][y_] == 0 && d + dist < res[x_][y_]){
                    pq.push({d+dist,{x_,y_}});
                    res[x_][y_] = d + dist;
                }
            }
        }
        if(res[n-1][m-1] == INT_MAX)
            return -1;
        
        return res[n-1][m-1] + 1;
    }
};