//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    typedef pair<int,int>P;
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<P,vector<P>,greater<P>>pq;
        
        pq.push({0,0}); // weight -- node
        
        vector<bool> inMst(V,false);
        int sum = 0;
        // vector<int> parent;  not needed here as path is not asked
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int wt    = p.first;
            int node  = p.second;
            
            if(inMst[node] == true)
                continue;
            
            inMst[node] = true;
            sum += wt;
            
            for(auto &tmp:adj[node]){
                int neighbor    = tmp[0];
                int neighbor_wt    = tmp[1];
                
                if(inMst[neighbor] == false){
                    pq.push({neighbor_wt,neighbor});
                    
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends