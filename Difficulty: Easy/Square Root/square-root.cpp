//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        int ans = 1 ; 
        if(n==1)return 1 ; 
        for(int i = 0 ; i <= n/2  ; i++){
            if(i*i>n)break ;
            if(i*i==n){
                return i ; 
            }
            ans = i ;  
        }
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
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends