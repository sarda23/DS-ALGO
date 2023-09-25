class Solution {
public:
    char findTheDifference(string s, string t) {
       int x = 0;
        
        for(char &ch:s){
            x ^= ch;
        }
        
        for(char &ch:t){
            x ^= ch;
        }
        return (char)x;
    }
};