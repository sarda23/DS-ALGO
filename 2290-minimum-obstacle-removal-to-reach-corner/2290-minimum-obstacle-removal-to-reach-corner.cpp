class Solution {
public:
    vector<pair<int,int>>direc={{0,1},{0,-1},{1,0},{-1,0}};
    int minimumObstacles(vector<vector<int>>& grid){
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=grid[0][0];
        set<pair<int,pair<int,int>>>s;
        s.insert({dist[0][0],{0,0}});
        
        while(!s.empty()){
            auto it=*s.begin();
            int x=it.second.first;
            int y=it.second.second;
            int curr_cost=it.first;
            s.erase(s.begin());
            if(x==n-1 and y==m-1)
                return curr_cost;
            
            for(auto dir:direc){
                int n_x=x+dir.first,n_y=y+dir.second;
                if(n_x>=0 and n_x<n and n_y>=0 and n_y<m and curr_cost+grid[n_x][n_y]<dist[n_x][n_y]){
                    dist[n_x][n_y]=curr_cost+grid[n_x][n_y];
                    s.insert({dist[n_x][n_y],{n_x,n_y}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};