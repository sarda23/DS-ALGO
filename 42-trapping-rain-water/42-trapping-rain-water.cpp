class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        int left[n],right[n],water_area[n]; int i; int sum=0;
         left[0]=arr[0];
         right[n-1]=arr[n-1];
         
         for(i=1;i<n;i++)
            left[i]=max(left[i-1],arr[i]);
         for(i=n-2;i>=0;i--)
            right[i]=max(right[i+1],arr[i]);
         for(i=0;i<n;i++)
            water_area[i]=min(left[i],right[i])-arr[i];
         for(i=0;i<n;i++)
            sum+=water_area[i];
            
        return sum;    
    }
};