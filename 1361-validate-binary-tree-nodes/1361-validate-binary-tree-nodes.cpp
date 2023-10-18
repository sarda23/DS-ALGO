class Solution {
public:
    vector<int>parent;
    int components;
    
    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    
    bool Union(int p,int child){
        
        if(find(child) != child)
            return false;
        if(find(p) == child)
            return false;
        
        parent[child] = p;
        components--;
        
        return true;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        components = n; // total n components hai
        parent.resize(n);
        
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        
        for(int i=0;i<n;i++){
            
            int node = i;
            int lc = leftChild[i];
            int rc = rightChild[i];
            
            if(lc != -1 && Union(node,lc) == false){
                return false;
            }
            
            if(rc != -1 && Union(node,rc) == false)
                return false;
            
        }
        
        return components == 1;
    }
};