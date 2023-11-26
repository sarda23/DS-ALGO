class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        
        vector<pair<int,int>> prevH; // {ht, col}
        
        for(int row = 0;row<n;row++){
            vector<pair<int,int>> currH; // {ht, col}
            vector<bool>seen(m,false);                
            for(auto [ht,col] : prevH){
                if(matrix[row][col] == 1){
                    currH.push_back({ht+1,col});
                    seen[col] = true;
                }
            }
            
            for(int col = 0;col<m;col++){
                if(seen[col] == false && matrix[row][col] == 1){
                    currH.push_back({1,col});
                }
            }
            
            for(int i=0;i<currH.size();i++){
                int h = currH[i].first;
                int b = i+1;
                
                res = max(res,b*h);
            }
            
            prevH = currH;
        }
        return res;
    }
};