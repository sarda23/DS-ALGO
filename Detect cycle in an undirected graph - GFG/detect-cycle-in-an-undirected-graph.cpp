//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool solve(vector<int>adj[],int u,vector<bool>&visited){
        queue<pair<int,int>>q;
        q.push({u,-1});
        
        visited[u] = true;
        
        while(!q.empty()){
            pair<int,int>P = q.front();
            q.pop();
            
            int source = P.first;
            int parent = P.second;
            
            for(int &v:adj[source]){
                if(visited[v] == false){
                    visited[v] = true;
                    q.push({v,source});
                }else if(v != parent){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        
        for(int i=0;i<V;i++){
            // can be disconnected graph so all nodes 
            if(!visited[i] and solve(adj,i,visited)){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends