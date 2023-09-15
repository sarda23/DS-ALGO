class Solution {
public:
    bool validbox(vector<vector<char>>& board,int sr,int er,int sc,int ec){
        // 3*3 -- should have unique element
        unordered_set<char> st;
        
        for(int i=sr;i<=er;i++){
            for(int j=sc;j<=ec;j++){
                if(board[i][j] == '.')
                    continue;
                
                if(st.find(board[i][j]) != st.end())
                    return false;
                
                st.insert(board[i][j]);
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        // trying brute force
        int n = board.size();
        int m = board[0].size();
        
        // validate rows 
        for(int row=0;row<n;row++){
            set<char>st;
            for(int col=0;col<m;col++){
                if(board[row][col] == '.')
                    continue;
                if(st.find(board[row][col]) != st.end())
                    return false;
                st.insert(board[row][col]);
            }
        }
         
        // validate col
        for(int col=0;col<m;col++){
            set<char>st;
            for(int row=0;row<n;row++){
                if(board[row][col] == '.')
                    continue;
                if(st.find(board[row][col]) != st.end())
                    return false;
                st.insert(board[row][col]);
            }
        }
        
        // validate boxes 3*3
        
        for(int sr=0;sr<9;sr+=3){
            int er = sr + 2;
            
            for(int sc=0;sc<9;sc+=3){
                int ec = sc + 2;
                
                if(!validbox(board,sr,er,sc,ec))
                    return false;
            }
        }
        
        return true;
    }
};