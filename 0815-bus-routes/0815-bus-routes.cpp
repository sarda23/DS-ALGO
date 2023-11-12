class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source == target)
            return 0;
        
        unordered_map<int,vector<int>>adj;  // key-stops   values = {indices}
        
        for(int route = 0; route< routes.size(); route++){
            
            for(auto &stops:routes[route]){
                adj[stops].push_back(route);
            }
        }
        
        queue<int>q;
        vector<bool>visited(501,false);
        
        for(auto &route:adj[source]){
            q.push(route);
            
            visited[route] = true;
        }
        
        int busCount = 1;   // source wala bus
        
        while(!q.empty()){
            
            int sz = q.size();
            while(sz--){
                int route = q.front();
                q.pop();
                
                for(auto &stop:routes[route]){
                    if(stop == target)
                        return busCount;
                    
                    for(auto &nextRoute:adj[stop]){
                        if(visited[nextRoute] == false){
                            visited[nextRoute] = true;
                            q.push(nextRoute);
                        }
                    }
                }
            }
            busCount++;
        }
        return -1;
    }
};