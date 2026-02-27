class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V) ; 
        for(auto&i :edges){
            adj[i[0]].push_back(i[1]) ; 
            adj[i[1]].push_back(i[0]) ; 
        }
        vector<bool>visited(V,0) ; 
        vector<int>parent(V) ;
        for(int i = 0 ; i < V ;i++){
           if(!visited[i]){
                parent[i] = i ; 
                visited[i] = 1; 
                queue<int>q ; 
                q.push(i) ; 
                while(!q.empty()){
                    int node = q.front() ; q.pop() ; 
                    for(int j : adj[node]){
                        if(!visited[j]){
                            parent[j] = node ; 
                            visited[j] = true ; 
                            q.push(j) ; 
                        }
                        else if(visited[j]&&parent[node]!=j){
                            return true ; 
                        }
                    }
                }
           }
        }
        return false ;  
    }
};