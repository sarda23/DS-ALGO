class Solution {
public:
    // coding decoded 
    vector<vector<bool>>vis;
    bool dfs(vector<vector<char>>&board,string &word,int i, int j,int index){
        if(index==word.size())
            return true;
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size() or vis[i][j]==true)
            return false;
        if(board[i][j]!=word[index])
            return false;
        vis[i][j]=true;
        if(dfs(board,word,i,j+1,index+1) or dfs(board,word,i,j-1,index+1) or dfs(board,word,i+1,j,index+1) or dfs(board,word,i-1,j,index+1))
            return true;
        
        vis[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word){
        vis.resize(board.size(),vector<bool>(board[0].size()));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]){
                    if(dfs(board,word,i,j,0))
                        return true;
                }
            }
        }
        return false;
    }
};