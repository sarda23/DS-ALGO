class Solution {
public:
    int minDeletions(string s) {
        int del=0;
        vector<int>fre(26,0);
        for(char ch:s)
            fre[ch-'a']++;
        for(auto it:fre)
            cout<<it<<" ";
        set<int>unique_fre;
        for(int count:fre){
            while(count>0 and unique_fre.find(count)!=unique_fre.end()){
                del++;
                count--;
            }
            unique_fre.insert(count);
        }
        return del;
    }
};