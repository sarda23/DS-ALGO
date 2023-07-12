//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,vector<int>&res){
        if(visited[u])
            return;
        
        visited[u] = true;
        res.push_back(u);
        for(int &v:adj[u]){
            if(!visited[v])
                dfs(adj,v,visited,res);
        }
        return;
    }
    
    vector<int> dfsOfGraph(int V, vector<int> g[]) {
        // Code here
        unordered_map<int,vector<int>>adj;
        
        for(int u=0;u<V;u++){
            
            for(auto v=g[u].begin();v!=g[u].end();v++){
                adj[u].push_back(*v);
            }
        }
        
        vector<int>res;
        vector<bool>visited(V,false);
        
        dfs(adj,0,visited,res);
        
        return res;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends