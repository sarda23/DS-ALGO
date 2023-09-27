class Solution {
public:
    
    int n;
    pair<int,int> getcoor(int num){
        int rowtop = (num-1)/n;
        int rowbot = (n-1) - rowtop;
        
        int col = (num-1)%n;
        //agar right to left hai 
        if((n%2==1 && rowbot%2==1) or (n%2==0 && rowbot%2==0) ){
            col = (n-1) - col;
        }
        return {rowbot,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        
        int steps = 0;
        queue<int>q;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[n-1][0] = true; // starting point
        
        q.push(1);
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int x = q.front();
                q.pop();
                
                if(x == n*n)
                    return steps;
                
                for(int k=1;k<=6;k++){
                    int val = x+k;
                    
                    if(val > n*n)
                        break;
                    
                    pair<int,int> coord = getcoor(val);
                    
                    int r = coord.first;
                    int c = coord.second;
                    
                    if(visited[r][c] == true)
                        continue;
                    
                    visited[r][c] = true;
                    
                    if(board[r][c] == -1){
                        q.push(val);
                    }else{
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};