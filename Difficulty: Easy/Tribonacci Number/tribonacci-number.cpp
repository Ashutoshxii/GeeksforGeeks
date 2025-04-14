//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int nthTribonacci(int n) {
        // code here
        if(n==0)return 0 ; 
        if(n<3)return 1 ; 
        vector<int> vec(n+1) ; 
        vec[0] = 0 ;
        vec[1] = 1 ;
        vec[2] = 1 ; 
        for(int i = 3 ; i<=n ; i++ ){
            vec[i] = vec[i-1]+vec[i-2]+vec[i-3] ; 
        }
        return vec[n] ; 
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.nthTribonacci(n);

        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends