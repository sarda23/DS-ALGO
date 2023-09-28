class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        // last index = n-1
        
        unordered_map<int,vector<int>>mp;
        vector<bool>visited(n,false);
        
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
            // number -- indices
        }
        
        // map populated ho chuka hai
        // now we have to perform BFS
        
        queue<int>q;
        q.push(0); // starting position
        visited[0] = true;
        
        int steps = 0;
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int curr = q.front();
                q.pop();
                
                int left = curr - 1;
                int right = curr + 1;
                
                if(curr == n-1)
                    return steps;
                
                if(left>=0 and !visited[left]){
                    q.push(left);
                    visited[left] = true;
                }
                
                if(right<=n-1 and !visited[right]){
                    q.push(right);
                    visited[right] = true;    
                }
                
                for(int &idx : mp[arr[curr]]){
                    if(!visited[idx]){
                        q.push(idx);
                        visited[idx] = true;
                    }
                }
                mp.erase(arr[curr]);
            }
            steps++;
        }
        return -1;
    }
};