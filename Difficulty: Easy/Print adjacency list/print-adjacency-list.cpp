class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // Code here
        vector<vector<int>>vec(V) ; 
        
        for(auto i : edges){
            vec[i.first].push_back(i.second) ;  
            vec[i.second].push_back(i.first) ;  
        }
        return vec  ; 
    }
};