//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int>path;
        
        unordered_map<int,vector<pair<int,int>>>adj;
        
        for(auto &vec:edges){
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>res(n+1,INT_MAX);
        vector<int>parent(n+1);
        for(int i=0;i<n+1;i++)
            parent[i] = i;
            
        res[1] = 0;
        pq.push({0,1});
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &it:adj[node]){
                int adjnode = it.first;
                int dist = it.second;
                
                if(d+dist < res[adjnode]){
                    res[adjnode] = d + dist;
                    pq.push({d+dist,adjnode});
                    parent[adjnode] = node;
                }
            }
        }
        if(res[n] == INT_MAX)
            return {-1};
        
        int destination = n;
        while(parent[destination] != destination){
            path.push_back(destination);
            destination = parent[destination];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends