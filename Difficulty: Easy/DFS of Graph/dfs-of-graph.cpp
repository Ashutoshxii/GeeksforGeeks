class Solution {
  public:
  
    
    void solve(vector<vector<int>>&adj , vector<int>&ans,int node,vector<bool>&visited){
        if(!visited[node]){
            visited[node] = 1 ; 
            ans.push_back(node) ; 
            for(int i : adj[node]){
                solve(adj,ans,i,visited) ; 
            }
        }
        return ; 
        
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> ans ; 
        vector<bool>visited(adj.size()) ; 
        
        // for(int i : adj[0]){
        solve(adj,ans,0,visited) ; 
        // }
        
        return ans ; 
        
        
        
    }
};