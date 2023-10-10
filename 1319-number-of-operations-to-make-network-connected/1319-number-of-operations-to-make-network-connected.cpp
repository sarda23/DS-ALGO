class Solution {
public:
    vector<int>parent,rank;
    
    int find(int x){
        if(x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x,int y){
        int parent_x = find(x);
        int parent_y = find(y);
        
        if(parent_x == parent_y)
            return;
        else if(rank[parent_x] > rank[parent_y])
            parent[parent_y] = parent_x;
        else if(rank[parent_x] < rank[parent_y])
            parent[parent_x] = parent_y;
        else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n-1)
            return -1;
        
        parent.resize(n);
        rank.resize(n);
        
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 0;
        }
        // initial all components are not connected
        int components = n;
        
        for(auto &vec:connections){
            if(find(vec[0]) != find(vec[1])){
                Union(vec[0],vec[1]);
                components--;
            }
        }
        return components-1;
    }
};