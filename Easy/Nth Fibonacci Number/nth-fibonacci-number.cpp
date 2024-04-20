//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        if(n<3){
            return 1 ;
        }
        int a = 0 ;  
        int b = 1 ;
        int s = 0 ; 
        for(int i = 2 ; i <= n ;i++){
            s = (a+b)%1000000007 ; 
            a = b ; 
            b = s ;
        }
        return s ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends