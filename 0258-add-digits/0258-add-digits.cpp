class Solution {
public:
    int sum = 0;
    int digit(int num){
        
        int count = 0;
        sum=0;
        
        while(num!=0){
            sum += num%10;
            num/=10;
            count++; // to count the num of digits
        }
        return count;
    }
    int addDigits(int num) {
        while(digit(num) > 1){
            num = sum;
        }
        
        return sum;
    }
};