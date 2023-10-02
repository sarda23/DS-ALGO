class Solution {
public:
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    int shortestPathAllKeys(vector<string>& grid){
        int n = grid.size(),m = grid[0].size();

        queue<vector<int>> q; // { x, y, steps, curr_key}

        int count = 0;

        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '@')
                    q.push({i,j,0,0});
                else if(grid[i][j] >= 'a' && grid[i][j] <= 'f'){
                    count++;
                }
            }
        }

        int final_key_status_decimal = pow(2,count) -1;

        int visited[n][m][final_key_status_decimal+1];

        memset(visited,0,sizeof(visited));

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            int i                = temp[0];
            int j                = temp[1];
            int steps            = temp[2];
            int curr_key_status  = temp[3];

            if(curr_key_status == final_key_status_decimal)
                return steps;
            
            for(auto &dir:directions){
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if(new_i>=0 and new_j>=0 and new_i<n and new_j<m and grid[new_i][new_j] != '#'){

                    char ch = grid[new_i][new_j];

                    if(ch >= 'A' and ch <= 'F'){//lock
                        if(visited[new_i][new_j][curr_key_status] == 0 and ((curr_key_status >> (ch-'A')) & 1) == 1){
                            visited[new_i][new_j][curr_key_status] = 1;
                            q.push({new_i,new_j,steps+1,curr_key_status});
                        }
                    }else if(ch >= 'a' and ch <= 'f'){

                            int new_key_status = curr_key_status | (1<<(ch-'a'));

                            if(visited[new_i][new_j][new_key_status] == 0 ){
                            visited[new_i][new_j][new_key_status] = 1;
                            q.push({new_i,new_j,steps+1,new_key_status});
                            }
                    }else{
                        if(visited[new_i][new_j][curr_key_status] == 0){
                            visited[new_i][new_j][curr_key_status] = 1;
                            q.push({new_i,new_j,steps+1,curr_key_status});          
                        }
                    }
                }
            }
        }

        return -1;
    }
};