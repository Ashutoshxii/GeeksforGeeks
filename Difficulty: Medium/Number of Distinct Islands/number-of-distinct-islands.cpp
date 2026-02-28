// User function Template for C++

class Solution {
  public:
    void dfs(int i,int j,int bi,int bj,vector<pair<int,int>>&v,vector<vector<bool>>&visited,vector<vector<int>>&grid){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||visited[i][j]||grid[i][j]==0){
            return  ; 
        }
        visited[i][j] = true ; 
        v.push_back({i-bi,j-bj}) ; 
        dfs(i+1,j,bi,bj,v,visited,grid) ; 
        dfs(i-1,j,bi,bj,v,visited,grid) ; 
        dfs(i,j+1,bi,bj,v,visited,grid) ; 
        dfs(i,j-1,bi,bj,v,visited,grid) ; 
        return ; 
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        set<vector<pair<int,int>>>st ; 
        int n  = grid.size() ; int m = grid[0].size() ; 
        vector<vector<bool>>visited(n,vector<bool>(m,0)) ; 
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ;j++){
                if(!visited[i][j]&&grid[i][j]){
                    vector<pair<int,int>>v ; 
                    dfs(i,j,i,j,v,visited,grid) ;
                    st.insert(v) ; 
                }
            }
        }
        return st.size()  ; 
    }
};
