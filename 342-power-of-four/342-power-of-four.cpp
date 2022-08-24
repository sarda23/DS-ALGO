class Solution {
public:
    bool isPowerOfFour(int n){
        if(n<=0)
            return false;
        if((n&(n-1))==0){   // power of 2
            // check for power of 4
            for(int i=0;i<32;i++){
                //right shift operation
                if(((n>>i)&1)==1){
                    //index where we got one
                    if(i%2==0)
                        return true;
                }
            }
        }
        return false;
    }
};