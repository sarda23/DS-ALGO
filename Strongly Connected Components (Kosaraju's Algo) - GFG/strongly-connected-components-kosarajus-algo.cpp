//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	void dfsFill(vector<vector<int>>& adj,int u,vector<bool>&vis,stack<int>&st){
	    vis[u] = true;
	    
	    for(int &v:adj[u]){
	        if(!vis[v]){
	            dfsFill(adj,v,vis,st);
	        }
	    }
	    st.push(u);
	}
	
	void dfs(int u,vector<vector<int>>& adj,vector<bool>&vis){
	    vis[u] = true;
	    
	    for(int &v:adj[u]){
	        if(!vis[v]){
	            dfs(v,adj,vis);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        // step 1 -- store order of dfs in stack
        
        stack<int>st;
        vector<bool>visited(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfsFill(adj,i,visited,st);
            }
        }
        
        // step 2 -- make a reverse graph
        
        vector<vector<int>> adjReverse(V);
        
        for(int u=0;u<V;u++){
            for(int &v:adj[u]){
                // u --> v 
                adjReverse[v].push_back(u);
            }
        }
        
        // step 3 -- call dfs in the order of stack
        int ans=0;
        visited = vector<bool>(V,false); // reset visited
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                dfs(node,adjReverse,visited);
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends