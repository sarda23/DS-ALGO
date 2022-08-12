const int N=2010;
class Solution {
public:
    int vis[N];
    void dfs(int vertex,vector<int>g[]){
        vis[vertex]=1;
        for(auto child:g[vertex]){
            if(!vis[child])
                dfs(child,g);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>g[n];
        for(auto edge:edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++;
                dfs(i,g);
            }
        }
        return c;
    }
};