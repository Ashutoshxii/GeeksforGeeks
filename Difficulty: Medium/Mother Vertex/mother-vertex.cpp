class Solution {
  public:
    // Function to find a Mother Vertex in the Graph.
    int findMotherVertex(int V, vector<int> adj[]) {
        // Code here
        
        for(int i = 0 ; i  <V   ; i++){
            bool real = true ; 
            vector<bool>visited(V) ; 
            
            // vector<int>ans; 
            // vector<bool>visited(adj.size(),false) ; 
            queue<int> q ; 
            
            q.push(i) ; 
            visited[i] = true ; 
     
            
            
            while(!q.empty()){
                int top = q.front() ; 
                q.pop() ; 
                for(int j : adj[top]){
                    if(!visited[j]){
                        visited[j] = true ; 
                
                        q.push(j) ; 
                    }
                }
            }
            for(bool k : visited){
                if(!k){
                    real = false ; 
                    break ; 
                }
            }
            if(real)return i ; 
        }
        return -1 ; 
        
    }
};