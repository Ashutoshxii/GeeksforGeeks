class Solution {
  public:
    bool dfs(int node,vector<bool>&visited,vector<bool>&path,vector<vector<int>>&adj){
        visited[node] = 1 ;
        path[node] = 1 ; 
        for(int &neigh:adj[node]){
            if(!visited[neigh]){
                if(dfs(neigh,visited,path,adj))return true ; 
            }
            else if(path[neigh]){
                return true ; 
            }
        }
        path[node] = 0 ; 
        return false ; 
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V) ; 
        for(auto&i : edges){
            adj[i[0]].push_back(i[1]) ; 
        }
        vector<bool>visited(V,0),pathVisited(V,0) ; 
        for(int i = 0 ; i < V ;i++){
            if(!visited[i]){
                if(dfs(i,visited,pathVisited,adj))return true  ; 
            }
        }
        return false ;
    }
};