class Solution {
public:
    // can be done by max heap but it will be expensive
    // sorted -- so apply-- binary search
    // coding decoded
    int solve(int target,vector<vector<int>>&matrix){
        int cnt=0,n=matrix.size();
        int i=0,j=n-1;
        while(i<=n-1 and j>=0){
            if(matrix[i][j]>target)
                j--;
            else{
                i++;
                cnt=cnt+j+1;
            }
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int start=matrix[0][0],end=matrix[n-1][n-1];
        while(start<=end){
            int mid = start + (end-start)/2;
            int count = solve(mid,matrix);
            if(count<k)
                start=mid+1;
            else
                end=mid-1;
        }
        return start;
    }
};