class Solution {
public:
    static bool comp(int &a,int &b){
        return a%2<b%2;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(begin(nums),end(nums),comp);
        return nums;
    }
};