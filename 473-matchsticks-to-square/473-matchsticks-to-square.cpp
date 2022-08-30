class Solution{
private:
    bool dfs(vector<int>&nums,vector<int>sides,int index,int target){
        if(index==nums.size())
            return sides[0]==sides[1] and sides[1]==sides[2] and sides[2]==sides[3];
        
        for(int i=0;i<4;i++){
            // if current length is larger than target 
            if(sides[i]+nums[index]>target or (i>0 and sides[i]==sides[i-1]))
                continue;
            // if we have already checked one particular length
            /*int j = i;
            while (--j >= 0){
                if (sides[i] == sides[j]) 
                    break;
            }
            if (j != -1) 
                continue;
                */
            sides[i]+=nums[index];
            if(dfs(nums,sides,index+1,target))
                return true;
            sides[i]-=nums[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums){
        if(nums.size()<4)
            return false;
        int sum=0;
        for(auto el:nums)
            sum+=el;
        if(sum%4!=0)
            return false;
        
        sort(nums.begin(),nums.end(),[&](int a,int b){
           return a>b; 
        });
        vector<int>sides(4,0);
        return dfs(nums,sides,0,sum/4);
    }
};