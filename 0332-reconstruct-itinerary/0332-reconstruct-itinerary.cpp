class Solution {
public:
    unordered_map<string,vector<string>>adj;
    vector<string> res;
    int numTickets = 0;
    
    bool dfs(string fromAirport,vector<string>&path){
        path.push_back(fromAirport);
        
        if(path.size() == numTickets + 1){
            res = path;
            return true;
        }
        
        vector<string> &neighbours = adj[fromAirport];
        
        for(int i=0;i<neighbours.size();i++){
            string toAirport = neighbours[i];
            
            //remove kardo  cycle se bachne ke lia
            
            neighbours.erase(neighbours.begin()+i);
            
            if(dfs(toAirport,path) == true)
                return true;
            
            neighbours.insert(neighbours.begin()+i, toAirport);
        }
        
        path.pop_back();
        return false;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        numTickets = tickets.size();
        
        for(auto &it:tickets){
            
            string u = it[0];
            string v = it[1];
            
            adj[u].push_back(v);
        }
        
        // sort -- we want lexical order
        for(auto&edge:adj){
            sort(begin(edge.second),end(edge.second));
        }
        
        // now we have to perform dfs
        
        vector<string>path;
        dfs("JFK",path);
        
        return res;
    }
};