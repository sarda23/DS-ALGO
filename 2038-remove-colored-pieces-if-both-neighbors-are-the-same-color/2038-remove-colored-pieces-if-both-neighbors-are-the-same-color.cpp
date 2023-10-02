class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        
        int alice = 0;
        int bob = 0;
        
        for(int i=0;i<n-1;i++){
            if(i-1>=0 &&colors[i-1] == colors[i] && colors[i] == colors[i+1]){
                if(colors[i] == 'A')
                    alice++;
                else
                    bob++;
            }
        }
        return alice > bob;
    }
};