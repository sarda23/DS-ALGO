class Solution {
public:
    int n,m;
    vector<vector<int>>directions{{1,0},{-1,0},{0,-1},{0,1}};
    
    bool dfs(vector<vector<char>>& board,int i,int j,int idx,string &word){
        if(idx == word.length())
            return true;
        
        if(i<0 or i>=n or j<0 or j>=m or board[i][j] == '$')
            return false;
        
        if(board[i][j] != word[idx])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '$';
        
        for(auto &dir:directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            if(dfs(board,new_i,new_j,idx+1,word)){
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(board[i][j] == word[0] and dfs(board,i,j,0,word))
                    return true;
            }
        }
        return false;
    }
};