//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int n,vector<int>&vec ){
        if(n<3)return n ; 
        if(vec[n]!=-1)return vec[n] ; 
        return vec[n] =  solve(n-1,vec)+solve(n-2,vec) ; 
    }
    int countWays(int n) {
        // your code here
        vector<int> vec(n+1,-1) ; 
        return solve(n,vec) ; 
        
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends