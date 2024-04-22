//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
        vector<int> ans(n) ; 
        ans[0] = 1 ;
        ans[1] =1;
        ans[2] = 2;
        for(int i = 3 ; i< n ;i++){
            ans[i]=(ans[i-1]%1000000007+ans[i-2]%1000000007) ; 
        }
        return ans[n-1]%1000000007 ; 
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends