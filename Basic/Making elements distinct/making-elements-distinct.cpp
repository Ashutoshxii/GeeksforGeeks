//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// To find minimum sum of unique elements.
long long int minSum(int arr[], int n);




int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << minSum(a, n) << endl;
        
    }
}
// } Driver Code Ends


long long int minSum(int arr[], int n)
{
	// Complete the function
	int i = 0 ; 
	long long s = 0 ; 
	while(i<n){
	    if(arr[i]<arr[i+1]){
	        s+=arr[i] ;
	    }
	    else{
	        arr[i+1] = arr[i]+1 ;
	        s+=arr[i] ; 
	    }
	    i++;
	} 
	
	return s ; 
}