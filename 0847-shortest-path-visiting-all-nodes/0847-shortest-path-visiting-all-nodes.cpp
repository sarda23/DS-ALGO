class Solution {
public:
    typedef pair<int,int>p;
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n==1 or n==0)
            return 0;
        
        queue<p>q;
        set<p>st;
        
        for(int i=0;i<n;i++){
            int mask = (1<<i);
            q.push({i,mask});
            
            st.insert({i,mask});  
        }
        int all = pow(2,n) - 1; // or (1<<n) - 1 
        
        int path = 0;
        
        while(!q.empty()){
            int size = q.size();
            path++;
            
            while(size--){
                p curr = q.front();
                q.pop();
                
                int currNode = curr.first;
                int currMask = curr.second;
                
                for(int &adj:graph[currNode]){
                    
                    int nextMask = currMask | (1<<adj);
                    
                    if(nextMask == all)
                        return path;
                    
                    if(st.find({adj,nextMask}) == st.end()){
                        st.insert({adj,nextMask});
                        q.push({adj,nextMask});
                    }    
                }
                
            }
        }
        return -1;
    }
};