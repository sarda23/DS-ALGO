//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        int idx = -1;
        for(int i=0;i<n;i++){
            if(arr[i] == 0)
                idx =  i;
        }
        if(idx==-1)
            return -1;
        
        vector<int>t;
        int c = 0;
        for(int i=0;i<n;i++){
            while(arr[i] != 0){
                c++; i++;
            }
            if(arr[i] == 0 and c != 0){
                t.push_back(c);
                c=0;
            }
        }
        return t.size();
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends