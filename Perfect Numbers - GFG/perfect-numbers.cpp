//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
         long long sum=1;
        for(long long int i=2;i*i<=N;i++)
        {
            if(N%i==0)
            {
             sum=(sum%LLONG_MAX+i%LLONG_MAX)%LLONG_MAX;
            //  if (i != N / i)
              sum=(sum%LLONG_MAX+(N%LLONG_MAX/i%LLONG_MAX))%LLONG_MAX;
            }
        }
        //  cout<<sum<<endl;
         if(sum==N && N!=1) return 1;
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends