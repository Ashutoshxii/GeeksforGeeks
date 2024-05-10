//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int left = 0 ; 
	    int right = n-1 ; 
	    int mid = (left+right)/2 ;
	    int ans = INT_MAX ; 
	    int index = -1 ; 
	    while(left<=right){
	        mid = (left+right) / 2 ; 
	        if(arr[mid]>=arr[left]){
	            if(ans>arr[left]){
	                ans = arr[left] ;
	                index = left ; 
	            }
	            left = mid + 1 ; 
	        }
	        else{
	            if(ans>arr[mid]){
	                ans = arr[mid] ;
	                index = mid ; 
	            }
	            right = mid - 1 ;
	        }
	    }
	    return index ; 
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends