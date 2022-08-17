class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {
        vector<int>ans;
        unordered_map<char,int> mp;
	    for(int i=0;i<pat.length();i++)
	       mp[pat[i]]++;
	    int count=mp.size();   // distinct in map
	    int i=0,j=0,k=pat.length(),n=txt.length();
	    while(j<n){
	        if(mp.find(txt[j])!=mp.end()){
	            mp[txt[j]]--;
	            if(mp[txt[j]]==0)
	               count--;
	        }
	        if(j-i+1<k)
	             j++;
	        else if(j-i+1==k){
	            if(count==0)
	               ans.push_back(i);
	            if(mp.find(txt[i])!=mp.end()){
	                mp[txt[i]]++;
	                if(mp[txt[i]]==1)
	                   count++;
	            }
	              i++;j++;
	        }
	    }
	    return ans;
    }
};