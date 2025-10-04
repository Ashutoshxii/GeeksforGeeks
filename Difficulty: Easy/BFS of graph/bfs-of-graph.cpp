class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        
        vector<int>ans; 
        vector<bool>visited(adj.size(),false) ; 
        queue<int> q ; 
        
        q.push(0) ; 
        visited[0] = true ; 
        ans.push_back(0) ; 
        
        
        while(!q.empty()){
            int top = q.front() ; 
            q.pop() ; 
            for(int i : adj[top]){
                if(!visited[i]){
                    visited[i] = true ; 
                    ans.push_back(i) ;
                    q.push(i) ; 
                }
            }
        }
        return ans; 
        
    }
};