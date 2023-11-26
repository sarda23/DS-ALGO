class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        
        vector<int> prevRow(m,0);
        
        for(int row = 0;row<n;row++){
            vector<int>currRow = matrix[row];
            
            for(int col = 0;col<m;col++){
                
                if(currRow[col] == 1){
                    currRow[col] += prevRow[col];
                }
            }
            vector<int> h = currRow;
            sort(h.begin(),end(h),greater<int>());
            
            for(int i=0;i<m;i++){
                
                int base = i+1;
                int ht = h[i];
                
                res = max(res,base*ht);
            }
            
            prevRow = currRow;
        }
        
        return res;
    }
};