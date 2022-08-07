class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string,int>mp;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char ch=board[i][j];
                if(ch!='.')
                    if(mp[to_string(ch)+"R"+to_string(i)] || mp[to_string(ch)+"C"+to_string(j)] || mp[to_string(ch)+"B"+to_string(i/3)+"-"+to_string(j/3)])
                        return false;
                else{
                    mp[to_string(ch)+"R"+to_string(i)]++;
                    mp[to_string(ch)+"C"+to_string(j)]++;
                    mp[to_string(ch)+"B"+to_string(i/3)+"-"+to_string(j/3)]++;
                }
            }
        }
        return true;
    }
};