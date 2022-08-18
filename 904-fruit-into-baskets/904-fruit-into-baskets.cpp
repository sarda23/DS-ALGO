class Solution {
public:
    // similar to pick toys -- aditya verma sliding window 2nd last window
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int i=0,j=0,mx=0,n=fruits.size();
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()<=2){
                mx=max(mx,j-i+1);
                j++;
            }
            else if(mp.size()>2){
                while(mp.size()>2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0)
                        mp.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};