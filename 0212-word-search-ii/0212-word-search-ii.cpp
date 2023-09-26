class Solution {
public:
    vector<string> res;
    int n,m;
    // lets make the trie data structure
    // node struct for trie
    struct trieNode{
        bool endOfWord;
        string word;
        trieNode* children[26];
    };
    
    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        
        newNode->endOfWord = false;
        newNode->word = "";
        
        for(int i=0;i<26;i++){
            newNode->children[i] = NULL;
        }
        
        return newNode;
    }
    // root se start karenge and word ko insert karna hai
    void insert(trieNode* root,string &word){
        trieNode* crawler = root;
        // check for each character of word
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            
            if(crawler->children[ch-'a'] == NULL){
                crawler->children[ch-'a'] = getNode();
            }
            
            crawler = crawler->children[ch-'a'];
        }
        
        crawler->endOfWord = true;
        crawler->word = word;
    }
    
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    
    void findwords(vector<vector<char>>& board,int i,int j,trieNode* root){
        if(i<0 or j<0 or i>=n or j>=m)
            return;
        
        if(board[i][j] == '$' or root->children[board[i][j]-'a'] == NULL){
            return;
        }
        // yaha aaye hai toh matlab root ke children ke pass 
        // yeh hai board[i][j] - 'a'  wala
        
        root = root->children[board[i][j]-'a'];
        
        if(root->endOfWord == true){
            res.push_back(root->word);
            root->endOfWord = false;
            // yaha rukna nahi hai 
            // aur bhi aage word mil sakhte hai
        }
        
        char temp = board[i][j];
        board[i][j] = '$'; // marking visited
        
        // left right up down
        for(vector<int>&dir:directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            findwords(board,new_i,new_j,root);
        }
        board[i][j] = temp;
        
    }
    
    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size(); // row
        m = board[0].size(); // col
    
        // create root
        trieNode* root = getNode(); // root ban gaya
        // insert word's in the trie from words
        
        for(string &word:words){
            insert(root,word);
        }
        
        // ab words ko find karna start karna hai trie
        // trie ban chuka hai 
        
        // ek hi bar traverse karna hoga grid me
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char ch = board[i][j];
                
                // agar woh char hai toh 
                if(root->children[ch-'a'] != NULL){
                    // words find kar kar ke res me add kar 
                    // dega using dfs
                    findwords(board,i,j,root);
                }
            }
        }
        return res;
        
    }
};