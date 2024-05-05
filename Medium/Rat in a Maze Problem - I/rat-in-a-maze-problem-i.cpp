//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
   bool isSafe(int newx, int newy, vector<vector<bool>>& visited, vector<vector<int>>& arr, int n) {
    if (newx < n && newx >= 0 && newy < n && newy >= 0 && !visited[newx][newy] && arr[newx][newy] == 1) {
        return true;
    }
    return false;
    }

    void solve(int x , int y , vector<vector<int>>&arr ,vector<string>&ans, vector<vector<bool>>&visited,string path,int n  ){
        if(x==n-1&&y==n-1){
            ans.push_back(path) ; 
            return ; 
        }
        //DOWN ;
        if(isSafe(x+1,y,visited,arr,n)){
            visited[x][y] = 1 ;
            solve(x+1 , y , arr ,ans, visited,path+'D',n) ; 
            visited[x][y] = 0 ; 
        }
        //left 
        if(isSafe(x,y-1,visited,arr,n)){
            visited[x][y] = 1 ;
            solve(x,y-1, arr ,ans, visited,path+'L',n) ; 
            visited[x][y] = 0 ; 
        }
        //right 
        if(isSafe(x,y+1,visited,arr,n)){
            visited[x][y] = 1 ;
            solve(x,y+1, arr ,ans, visited,path+'R',n) ; 
            visited[x][y] = 0 ; 
        }
        //up
        if(isSafe(x-1,y,visited,arr,n)){
            visited[x][y] = 1 ;
            solve(x-1,y , arr ,ans, visited,path+'U',n) ; 
            visited[x][y] = 0 ; 
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans ; 
        if(!m[0][0]){
            ans.push_back("-1") ;
            return ans ; 
        }
        vector<vector<bool>> visited (n,vector<bool>(n,0)) ; 
        string path="" ; 
        solve(0,0,m,ans,visited,path,n) ; 
        return ans ; 
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends