class Solution {
public:
    vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<vector<int>>q;
        
        int i = 0, j = 0;
        //starting point
        q.push({0,0,k});
        
        bool visited[41][41][1601];
        memset(visited,false,sizeof(visited));
        
        int steps = 0;
        
        // start the bfs 
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                vector<int>temp = q.front();
                q.pop();
                
                int curr_i = temp[0];
                int curr_j = temp[1];
                int obs = temp[2];
                
                if(curr_i == n-1 and curr_j == m-1)
                    return steps;
                
                for(auto &dir:directions){
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];
                    
                    if(new_i<0 or new_i>=n or new_j<0 or new_j>=m)
                        continue;
                    
                    if(grid[new_i][new_j] == 0 and !visited[new_i][new_j][obs]){
                        q.push({new_i,new_j,obs});
                        visited[new_i][new_j][obs] = true;
                    }
                    else if(grid[new_i][new_j] == 1 and obs > 0 and !visited[new_i][new_j][obs-1]){
                        q.push({new_i,new_j,obs-1});
                        visited[new_i][new_j][obs-1] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};