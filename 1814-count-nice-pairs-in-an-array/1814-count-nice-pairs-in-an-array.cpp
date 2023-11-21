class Solution {
public:
    int mod = 1e9 + 7;
    
    int rev(int num){
        int ans = 0;
        
        while(num > 0){
            int rem = num%10;
            ans = (ans*10) + rem;
            num = num/10;
        } 
        return ans;
    }
    
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
            nums[i] = nums[i] - rev(nums[i]);
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            ans = (ans + mp[nums[i]])%mod;
            
            mp[nums[i]]++;
        }
        
        return ans;
    }
};