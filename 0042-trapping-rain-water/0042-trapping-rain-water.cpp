class Solution {
public:
    vector<int> getLeftMax(vector<int>&height,int n){
        vector<int>res(n);
        res[0] = height[0];
        
        for(int i =1;i<n;i++){
            res[i] = max(res[i-1],height[i]);
        }
        return res;
    }
    vector<int> getRightMax(vector<int>&height,int n){
        vector<int>res(n);
        res[n-1] = height[n-1];
        
        for(int i =n-2;i>=0;i--){
            res[i] = max(res[i+1],height[i]);
        }
        return res;
    }
    int trap(vector<int>& height) {
        int n = height.size(); // num of element
        
        vector<int>leftMax = getLeftMax(height,n);
        vector<int>rightMax = getRightMax(height,n);
        
        int sum = 0;
        
        for(int i =0 ;i<n;i++){
            int w = 1;
            int h = min(leftMax[i],rightMax[i]) - height[i];
            
            sum += w*h;
        }
        return sum;
    }
};