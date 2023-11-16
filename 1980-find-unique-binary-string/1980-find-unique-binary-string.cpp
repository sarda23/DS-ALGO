class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int>st;
        
        for(string &num:nums){
            st.insert(stoi(num,0,2)); // string to num - if string is binary-- 2
            // 2 ka matlab woh binary string hai
        }
        
        int n = nums.size();
        
        string res = "";
        
        for(int num =0; num<=n;num++){
            if(st.find(num) == st.end()){
                res = bitset<16>(num).to_string();
                
                return res.substr(16-n,n);
            }
        }
        
        return "";
    }
};