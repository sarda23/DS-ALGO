class Solution {
public:
    string removeDigit(string number, char digit) {
        for(int i=0;i<number.size()-1;i++){
            if(number[i]==digit and number[i]<number[i+1])
                return number.substr(0,i)+number.substr(i+1,number.size());
            
        }
        int last_occ=number.rfind(digit);
        return number.substr(0,last_occ)+number.substr(last_occ+1);
    }
};