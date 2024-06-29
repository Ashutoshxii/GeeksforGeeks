//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size() ;
        // bool arra[n+1][sum+1] ;
        // for(int i = 0 ; i < n+1 ; i++){
        //     for(int j = 0 ; j < sum+1 ; j++){
        //         if(i==0){
        //             arra[i][j] = false ;
        //         }
        //         if(j==0){
        //             arra[i][j] = true;
        //         }
        //     }
        // }
        vector<vector<bool>> arra(n + 1, vector<bool>(sum + 1, false));

        for (int i = 0; i <= n; i++) {
            arra[i][0] = true; 
        }
        for(int i = 1 ; i < n+1 ; i++){
            for(int j = 1 ; j < sum+1 ; j++){
                if(arr[i-1]<=j){
                    arra[i][j] = arra[i-1][j-arr[i-1]]||arra[i-1][j] ;
                }
                else{
                    arra[i][j] = arra[i-1][j] ; 
                }
            }
        }
        return arra[n][sum] ;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends