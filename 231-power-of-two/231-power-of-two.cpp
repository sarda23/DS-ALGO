class Solution {
public:
    bool isPowerOfTwo(int n){
        /*
        if(n==0 or n==INT_MIN)
            return false;
        int ans=n&(n-1);
        return ans==0;
        */
        
        // count the num of set bits
        if(n==0 or n==INT_MIN)
            return false;
        int count=0;
        for(int i=0;i<32;i++){
            if(((n>>i)&1)==1)
                count++;
            if(count>=2)
                return false;
        }
        return true;
    }
};