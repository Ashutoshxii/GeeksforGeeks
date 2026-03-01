// User function Template for C++
class Solution {
  public:
void dfs(int i,stack<int>&st,vector<bool>&visited,vector<vector<pair<int,int>>>&adj){
    visited[i] = 1 ;
    for(auto&neigh:adj[i]){
        if(!visited[neigh.first]){
            dfs(neigh.first,st,visited,adj) ; 
        }
    }
    st.push(i) ; 
}

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V) ;
        for(auto&i:edges){
            adj[i[0]].push_back({i[1],i[2]}) ;
        }
        vector<bool>visited(V,0) ;
        stack<int>st ; 
        for(int i = 0 ; i < V ;i++){
            if(!visited[i]){
                dfs(i,st,visited,adj) ; 
            }
        }
        vector<int>dist(V,INT_MAX) ; 
        dist[0]  = 0 ; 
        while(!st.empty()){
            int node = st.top() ; st.pop() ; 
            if(dist[node]!=INT_MAX){
                for(auto&i:adj[node]){
                int w = i.second ; 
                int neigh = i.first ; 
                if(dist[neigh]>w+dist[node]){
                    dist[neigh] = w + dist[node] ; 
                }
            }
            }
        }
        for(int&i:dist){
            if(i==INT_MAX)i=-1 ; 
        }
        return dist ;
        
    }
    
    
    
    
    
    
    
};
