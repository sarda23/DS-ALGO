class Solution {
public:
    
    int countoverlap(vector<vector<int>>& a, vector<vector<int>>&b,int rowoff,int coloff){
        int n = a.size();
        
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // find index of b from a ka index[i][j]
                
                /*
                a[i][j] = b[i+rowoff][j+coloff]
                */
                
                int b_i = i + rowoff;
                int b_j = j + coloff;
                
                if(b_i<0 or b_i>=n or b_j<0 or b_j>=n)
                    continue;
                
                if(a[i][j] == 1 and b[b_i][b_j] == 1)
                    count++;
            }
        }
        return count;
    }
    
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        // n*n matrix  row = n  col = n
        
        int maxOverlap = 0;
        
        for(int rowoff = -n+1;rowoff<n;rowoff++){
            for(int coloff = -n+1;coloff<n;coloff++){
                
                int count = countoverlap(a,b,rowoff,coloff);
                
                maxOverlap= max(maxOverlap,count);
            }
        }
        return maxOverlap;
    }
};