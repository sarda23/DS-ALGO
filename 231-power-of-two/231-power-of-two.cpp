class Solution {
public:
    bool isPowerOfTwo(int n){
        if(n==0 or n==INT_MIN)
            return false;
        int ans=n&(n-1);
        return ans==0;
    }
};