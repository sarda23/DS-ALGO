class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        int n = people.size();
        
        int i=0,j=n-1;
        int ans=0;
        while(i<=j){
            int sum = people[i] +people[j];
            
            if(sum > limit){
                j--;
                ans++;
            }else{
                i++;j--;
                ans++;
            }
        }
        return ans;
    }
};