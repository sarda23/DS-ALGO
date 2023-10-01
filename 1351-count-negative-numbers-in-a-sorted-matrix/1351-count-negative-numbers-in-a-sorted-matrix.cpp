class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int res = 0;
        int row = n-1;
        int col = 0;
        
        while(row>=0 and col<m){
            if(grid[row][col] >= 0)
                col++;
            else{
                res += m-col;
                row--;
            }
        }
        return res;
    }
};