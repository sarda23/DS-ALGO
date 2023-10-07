class Solution {
public:
    bool solve(unordered_map<int,vector<int>>&adj,int n,vector<int>& in){
        queue<int>q;
        int count = 0;
        
        for(int i=0;i<n;i++){
            if(in[i] == 0){
                q.push(i);
                count++;
            }
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int &v:adj[u]){
                in[v]--;
                if(in[v] == 0){
                    q.push(v);
                    count++;
                }
            }
        }
        
        return count == n?true:false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // cycle detection BFS - kanh's algorithm
        
        unordered_map<int,vector<int>>adj;
        
        vector<int> in(numCourses,0);
        
        for(auto &vec:prerequisites){
            int a = vec[0];
            int b = vec[1];
            
            // b -- > a
            adj[b].push_back(a);
            
            // arrow a me ja raha hai
            
            in[a]++;
        }
        
        // if cycle present -- not possible
        
        return solve(adj,numCourses,in);
    }
};