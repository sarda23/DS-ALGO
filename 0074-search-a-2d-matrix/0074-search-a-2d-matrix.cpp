class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m=matrix[0].size();
        
        /*
        int start = 0,end = n*m-1;

        while(start <= end){
            int mid = start + (end-start)/2;

            int row = mid/m;
            int col = mid%m;
            
            if(matrix[row][col] > target)
                end = mid-1;
            else if(matrix[row][col] < target)
                start = mid + 1;
            else
                return true;
        }
        return false;
        
        */
        
        // n - rows    m -  cols
        
        int i = 0,j = m-1;
        
        while(i<n && j>=0){
            if(matrix[i][j] > target){
                j--;
            }else if(matrix[i][j] < target){
                i++;
            }else{
                return true;
            }
        }
        
        return false;
    }
};