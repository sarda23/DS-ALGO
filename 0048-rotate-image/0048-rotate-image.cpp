class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose -- row ko col
        // 2nd step -- reverse the rows
        int n = matrix.size(),m=matrix[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};