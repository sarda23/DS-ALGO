class Solution {
public:
    int totalMoney(int n) {
        int monday       = 1;
        int money_final  = 0;
        
        while(n > 0){
            int money = monday;
            for(int day=1;day<=min(n,7);day++){
                money_final += money;
                money++;
            }
            n = n - 7;
            monday++;
        }
        
        return money_final;
    }
};