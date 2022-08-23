class Solution {
public:
    string convertToString(vector<char>a){
        string s="";
        for(auto ch:a){
            s+=ch;
        }
    
        return s;
    }
    set<string> getnextstates(string currentlock){
        set<string> newlock;
        vector<char>lock;
        
        for(int i=0;i<4;i++)
            lock.push_back(currentlock[i]);
        
        for(int i=0;i<4;i++){
            char ch =lock[i];
            // moving clockwise
            lock[i] = ch=='9'?'0':(char)(ch+1);
            newlock.insert(convertToString(lock));
            
            // moving anti-clockwise
            lock[i]= ch=='0'?'9':(char)(ch-1);
            newlock.insert(convertToString(lock));
            lock[i]=ch;
        }
        return newlock;
    }
    int openLock(vector<string>& deadends, string target) {
        set<string>visited;
        if(target=="" or target.size()==0)
            return -1;
        for(auto s:deadends)
            visited.insert(s);
        
        queue<string>q;
        int level=0;
        q.push("0000");
        while(q.size()>0){
            int sz=q.size();
            while(sz--){
                string currentlock=q.front(); 
                q.pop();
                if(visited.find(currentlock)!=visited.end())
                    continue;
                if(currentlock==target)
                    return level;
                
                for(string nextlock:getnextstates(currentlock))
                    if(visited.find(currentlock)==visited.end())
                        q.push(nextlock);
                visited.insert(currentlock);
            }
            level++;
        }
        return -1;
    }
};