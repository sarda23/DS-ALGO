class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        /*
        dir = 0 : left to right
        dir = 1 : top to down
        dir = 2 : right to left
        dir = 3 : down to top
        */
        
        vector<int>res;
        int dir = 0;
        int top = 0;
        int down = m - 1;
        int left = 0;
        int right = n-1;
        while(top <= down and left <= right){
            
            if(dir == 0){
                // left to right
                // constant : row
                
                for(int i=left;i<=right;i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            
            if(dir == 1){
                // top to down
                // constant : col (right)
                
                for(int i=top;i<=down;i++){
                    res.push_back(matrix[i][right]);
                }
                
                right--;
            }
            
            if(dir == 2){
                // right to left
                // constant : row (down)
                
                for(int i=right;i>=left;i--){
                    res.push_back(matrix[down][i]);
                }
                down--;
            }
            
            if(dir == 3){
                // bottom to top 
                // constant : col (left)
                
                for(int i=down;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
            
                left++;
            }
            dir = (dir+1)%4;
        }
        return res;
    }
};