class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size() ;
        vector<vector<int>>adj(26) ; 
        vector<bool>active(26,0) ; 
        vector<int>indegree(26,0) ; 
        
        for(int i = 0 ; i < n-1 ;i++){
            int j = 0 ; 
            while(j<words[i].size()&&j<words[i+1].size()&&words[i][j]==words[i+1][j]){
                j++ ; 
            }
            if(j==words[i+1].size()&&words[i].size()>words[i+1].size()){
                return "" ; 
            } 
            if(j<words[i].size()&&j<words[i+1].size()){
                int p =words[i][j]-'a' ;
                int q = words[i+1][j]-'a';
                adj[p].push_back(q) ;   
                // active[p] = 1 ;
                // active[q] =1 ; 
                indegree[q]++ ; 
            }   
        }
        for(string&st : words){
            for(char&ch : st){
                active[ch-'a'] = 1 ; 
            }
        }
        
        queue<int>q ; 
        int total = 0 ; 
        for(int i = 0 ; i < 26 ;i++){
            if(active[i]&&indegree[i]==0){
                q.push(i) ; 
            }
            if(active[i])total++ ; 
        }
        string st = "" ; 
        int count  = 0 ;
        while(!q.empty()){
            int node = q.front() ; q.pop() ; 
            count++ ;
            st+= (node+'a') ; 
            for(int&i : adj[node]){
                indegree[i]-- ;
                if(indegree[i]==0){
                    q.push(i) ; 
                }
            }
        }
        if(count<total)return "" ;
        return st; 
        
        
    }
};