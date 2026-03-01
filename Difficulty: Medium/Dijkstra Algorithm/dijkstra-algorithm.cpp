class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V) ; 
        for(auto&i:edges){
            adj[i[0]].push_back({i[1],i[2]}) ; 
            adj[i[1]].push_back({i[0],i[2]}) ; 
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q ; 
        q.push({0,src}) ; 
        vector<int>dist(V,INT_MAX) ; 
        dist[src] = 0 ; 
        while(!q.empty()){
            int node = q.top().second ;
            int d = q.top().first ; q.pop() ; 
            
            if(dist[node]==INT_MAX)continue ; 
            for(auto&i : adj[node]){
                int neigh = i.first ;
                int w = i.second ;
                if(dist[neigh]>dist[node]+w){
                    dist[neigh] = dist[node] + w ;
                    q.push({dist[neigh],neigh}) ; 
                }
            }
        }
        return dist  ; 
    }
};