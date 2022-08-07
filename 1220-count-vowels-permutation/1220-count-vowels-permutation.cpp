class Solution {
public:
    int mod=1e9+7;
    unordered_map<string,long>mp;
    
    long solve(int remainchar,char prevchar){
        if(remainchar==0)
            return 1;
        string key=""+to_string(remainchar)+to_string(prevchar);
        if(mp.find(key)!=mp.end())
            return mp[key];
        long total=0;
        switch(prevchar){
            case 'a':
                total=(solve(remainchar-1,'e'))%mod;
                break;
            case 'e':
                total=(solve(remainchar-1,'a')+solve(remainchar-1,'i'))%mod;
                break;
            case 'i':
                total=(solve(remainchar-1,'a')%mod+solve(remainchar-1,'e')%mod+solve(remainchar-1,'o')%mod+solve(remainchar-1,'u')%mod)%mod;
                break;
            case 'o':
                total=(solve(remainchar-1,'i')+solve(remainchar-1,'u'))%mod;
                break;    
            case 'u':
                total=(solve(remainchar-1,'a'))%mod;
                break;
        }
        return mp[key]=total;
    }
    int countVowelPermutation(int n) {
        char ch[]={'a','e','i','o','u'};
        long total=0;
        for(auto c:ch)
            total=(total+solve(n-1,c))%mod;
        return (int)total;
    }
};