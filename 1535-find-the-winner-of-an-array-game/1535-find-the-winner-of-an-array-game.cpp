class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n =arr.size();
        
        int maxE = *max_element(begin(arr),end(arr));
        
        if(k>=n)
            return maxE;
        
        int winner = arr[0];
        int win = 0;
        
        for(int i=1;i<n;i++){
            
            if(arr[i] > winner){
                winner = arr[i];
                win    = 1;
            }else{
                win++;
            }
            
            if(win == k or winner == maxE){
                return winner;
            }
        }
        return -1;
    }
};