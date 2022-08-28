class Solution {
public:
    bool isvalid(int x,int y,vector<vector<int>>&board){
        return x>=0 and y>=0 and x<board.size() and y<board[0].size();
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> dx ={0,0,1,1,1,-1,-1,-1};
        vector<int> dy ={1,-1,1,-1,0,0,1,-1};
        int n=board.size(),m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count_live=0;
                
                for(int k=0;k<8;k++){
                    int curr_x= i + dx[k], curr_y = j + dy[k];
                    if(isvalid(curr_x,curr_y,board) and abs(board[curr_x][curr_y])==1)
                        count_live++;
                }
                if(board[i][j]==1 and (count_live<2 or count_live>3))
                    board[i][j]=-1;
                
                if(board[i][j]==0 and count_live==3)
                    board[i][j]=2;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]>=1)
                    board[i][j]=1;
                else
                    board[i][j]=0;
            }
        }
    }
};