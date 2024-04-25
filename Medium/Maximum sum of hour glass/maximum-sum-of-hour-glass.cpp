//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int sumer (int istart , int jstart,vector<vector<int>> mat){
        int s = 0 ; 
        for(int i = istart ; i< istart+3 ; i++){
            for(int j = jstart ; j < jstart+3 ; j++){
                s+=mat[i][j];
            }
        }
        s=s-mat[istart+1][jstart]-mat[istart+1][jstart+2] ; 
        return s ; 
    }
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        // code here
        if(n<3||m<3){
            return -1 ; 
        }
        int maxi = 0 ;
        int i = 0 ; 
        int j = 3 ;
        
        int k = 0 ;
        int l = 3 ;
        // for(i = 0 ; i<= n-3;i++){
        //     for(j = 0 ; j<=m-3 ;j++){
        //         int sumi = sumer(i,j,mat) ;
        //         maxi=max(maxi,sumi) ;
                 
        //     }
        // }
        int sumi = 0 ; 
            
         while(i<n-2 ){
            sumi = sumer(i,k,mat) ;
            maxi=max(maxi,sumi) ;
            k++;
            while(k<=m-3&&i<=n-3){
                sumi = sumi+ mat[i][k+2]+mat[i+1][k+1] + mat[i+2][k+2] - mat[i][k-1]
            - mat[i+1][k] - mat[i+2][k-1] ;
            
            maxi=max(maxi,sumi) ;
            k++ ; 
            }
            maxi=max(maxi,sumi) ;
            k = 0 ; 
            i++ ; 
            
        }
        return maxi ; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends