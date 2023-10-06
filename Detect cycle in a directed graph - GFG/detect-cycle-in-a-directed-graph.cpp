//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int N, vector<int> adj[]) {
        // code here
        queue<int>q;
        
        vector<int>in(N,0);
        
        for(int u=0;u<N;u++){
            for(int &v:adj[u]){
                in[v]++;
            }
        }
        int c=0;
        for(int i=0;i<N;i++){
            if(in[i] == 0){
                q.push(i);
                c++;
            }
        }
        
        // simple BFS
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int &v:adj[u]){
                in[v]--;
                
                if(in[v] == 0){
                    q.push(v);
                    c++;
                }
            }
        }
        
        if(c == N)
            return false;
            
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends