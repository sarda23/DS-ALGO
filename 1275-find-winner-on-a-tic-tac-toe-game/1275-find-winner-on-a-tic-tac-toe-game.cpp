class Solution {
public:
    string check(vector<vector<char>>&board){
        // checking row
        for(int i=0;i<3;i++){
            int counta=0,countb=0;
            for(int j=0;j<3;j++){
                if(board[i][j]=='X')
                    counta++;
                else if(board[i][j]=='O')
                    countb++;
            }
            if(counta==3)
                return "A";
            if(countb==3)
                return "B";
        }
        // checking col
         for(int i=0;i<3;i++){
            int counta=0,countb=0;
            for(int j=0;j<3;j++){
                if(board[j][i]=='X')
                    counta++;
                else if(board[j][i]=='O')
                    countb++;
            }
            if(counta==3)
                return "A";
            if(countb==3)
                return "B";
        }
        // checking diagonal
        if(board[0][0]=='X' and board[1][1]=='X' and board[2][2]=='X')
            return "A";
        if(board[0][0]=='O' and board[1][1]=='O' and board[2][2]=='O')
            return "B";
        // other diagonal
        if(board[2][0]=='X' and board[1][1]=='X' and board[0][2]=='X')
            return "A";
        if(board[2][0]=='O' and board[1][1]=='O' and board[0][2]=='O')
            return "B";
        // check for draw
        int c=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]=='X' or board[i][j]=='O')
                    c++;
            }
        }
        if(c!=9)
            return "Pending"; 
        return "Draw";
    }
    string tictactoe(vector<vector<int>>& moves) {
        int n=moves.size();
        vector<vector<char>>board(3,vector<char>(3,'.'));
        for(int i=0;i<n;i++){
            if(i%2==0)//a will play
            {
                board[moves[i][0]][moves[i][1]]='X';
            }
            else{
                board[moves[i][0]][moves[i][1]]='O';
            }
        }
        return check(board);
    }
};