class Solution {
public:
    int numberOfMatches(int n) {
        int match  = 0;
        int remain = n;
        while(remain > 1){
            
            if(remain%2==0){
                match += remain/2;
                remain = remain/2;
            }else{
                match +=  (remain-1)/2;
                remain = (remain-1)/2 + 1;
            }
        }
        
        return match;
    }
};