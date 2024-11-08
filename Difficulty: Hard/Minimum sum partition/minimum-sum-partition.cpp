//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0 ; 
	    for(int i = 0 ; i< n ; i++){
	        sum+=arr[i];
	    }
	    int row = n+1 ;
	    int col = sum + 1 ;  
	   // int sum = 0 ;
	    vector<vector<bool>> vec (row, vector<bool>(col , false )) ;
	    for(int i = 0 ; i < row ; i++){
	        vec[i][0] = true ; 
	    }
	    for(int i = 1 ; i< row ; i++){
	        for(int j = 1 ; j < col ; j++){
	            if(arr[i-1]<=j){
	                vec[i][j] = vec[i-1][j-arr[i-1]]||vec[i-1][j];
	            }
	            else{
	                vec[i][j] = vec[i-1][j] ;
	            }
	        }
	    }
	    int mini = INT_MAX ;
	    int halfSum = sum/2 ;
	    for(int i = 0 ; i <= halfSum  ; i++){
	        if(vec[row-1][i]){
	            mini = min(mini, sum - (2*i)) ;
	        }
	    }
	    return mini ; 
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends