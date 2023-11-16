class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        
        sort(begin(arr),end(arr));
        int maxE = -1;
        
        for(int i=0;i<n;i++){
            
            if(i == 0)
                arr[0] = 1;
            else if(arr[i] - arr[i-1] > 1){
                arr[i] = arr[i-1] + 1;
            }
            maxE = max(maxE,arr[i]);
        }
        
        return maxE;
    }
};