class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>&adj,vector<int>&color,int curr,int currColor){
        color[curr] = currColor;
        
        for(int &v:adj[curr]){
            if(color[v] == color[curr])
                return false;
            if(color[v] == -1){
                color[v] = 1 - currColor;
                if(dfs(adj,color,v,color[v]) == false)
                   return false;
            }
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(dfs(adj,color,i,1) == false)
                    return false;
            }
        }
        return true;
    }
};